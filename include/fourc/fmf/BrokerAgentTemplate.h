/*
 * This file is part of fourc-qpid-manager.
 *
 * fourc-qpid-manager is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * fourc-qpid-manager is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser Public License for more details.
 *
 * You should have received a copy of the GNU Lesser Public License
 * along with fourc-qpid-manager.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FOURC_FMF_BROKERAGENTTEMPLATE_H
#define FOURC_FMF_BROKERAGENTTEMPLATE_H

#include "fourc/fmf/codec/ExceptionDecoder.h"
#include "fourc/fmf/codec/ResponseDecoder.h"

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/lexical_cast.hpp>

#include <string>
#include <memory>
#include <vector>
#include <chrono>

namespace fourc {
namespace fmf {

template<typename AddressT, typename SessionT, typename ReceiverT, typename MessageT, typename DurationT, typename VariantT>
class BrokerAgentTemplate {
public:
  BrokerAgentTemplate(const std::shared_ptr<SessionT>& session) : session(session), correlator(0) {
  }

  /**
   * \brief Returns a reference to the session used by the broker agent to communicate with the broker.
   * Not to be confused with getSession(sessionName).
   * @return
   */
  const std::shared_ptr<SessionT>& getConnectionSession() const {
    return session;
  }

  /**
   * \brief Gets an ACL object
   *
   * @param name
   * @return an ACL object
   */
  const std::shared_ptr<Acl> getAcl() {
    return getSingleObject<Acl>();
  }

  /**
   * \brief Gets a broker object
   *
   * @param name
   * @return a broker object or null
   */
  const std::shared_ptr<Broker> getBroker() {
    return getSingleObject<Broker>();
  }

  /**
   * \brief Gets a cluster object
   *
   * @param name
   * @return an existing cluster object or null
   */
  const std::shared_ptr<Cluster> getCluster() {
    return getSingleObject<Cluster>();
  }

  /**
   * \brief Gets a connection with the given name
   * Not to be confused with a qpid::messaging::Connection
   *
   * @param name
   * @return an existing connection or null
   */
  const std::shared_ptr<Connection> getConnection(const std::string& name) {
    return getObject<Connection>(name);
  }

  /**
   * \brief Gets an exchange with the given name
   *
   * @param name
   * @return an existing exchange or null
   */
  const std::shared_ptr<Exchange> getExchange(const std::string& name) {
    return getObject<Exchange>(name);
  }

  /**
   * \brief Gets an HA broker object
   *
   * @param name
   * @return an existing HA broker object or null
   */
  const std::shared_ptr<HaBroker> getHaBroker() {
    return getSingleObject<HaBroker>();
  }

  /**
   * \brief Gets a broker memory stats object
   *
   * @param name
   * @return a broker memory stats object
   */
  const std::shared_ptr<Memory> getMemory() {
    return getSingleObject<Memory>();
  }

  /**
   * \brief Gets a queue with the given name
   *
   * @param name
   * @return an existing queue or null
   */
  const std::shared_ptr<Queue> getQueue(const std::string& name) {
    return getObject<Queue>(name);
  }

  /**
 * \brief Gets a session with the given name
 *
 * @param name
 * @return an existing session or null
 */
  const std::shared_ptr<Session> getSession(const std::string& name) {
    return getObject<Session>(name);
  }

  /**
 * \brief Gets a subscription with the given name
 *
 * @param name
 * @return an existing subscription or null
 */
  const std::shared_ptr<Subscription> getSubscription(const std::string& name) {
    return getObject<Subscription>(name);
  }

  /**
 * \brief Gets a list of all bindings on the broker
 * @return
 */
  std::vector<std::shared_ptr<Binding>> getBindings() {
    return classQuery<Binding>();
  }

  /**
 * \brief Gets a list of all connections on the broker
 * @return
 */
  std::vector<std::shared_ptr<Connection>> getConnections() {
    return classQuery<Connection>();
  }

  /**
   * \brief Gets a list of all exchanges on the broker
   * @return
   */
  std::vector<std::shared_ptr<Exchange>> getExchanges() {
    return classQuery<Exchange>();
  }

  /**
   * \brief Gets a list of all links on the broker
   * @return
   */
  std::vector<std::shared_ptr<Link>> getLinks() {
    return classQuery<Link>();
  }

  /**
   * \brief Gets a list of all queues on the broker
   * @return
   */
  std::vector<std::shared_ptr<Queue>> getQueues() {
    return classQuery<Queue>();
  }

  /**
   * \brief Gets a list of all sessions on the broker
   * @return
   */
  std::vector<std::shared_ptr<Session>> getSessions() {
    return classQuery<Session>();
  }

  /**
   * \brief Gets a list of all subscriptions on the broker
   * @return
   */
  std::vector<std::shared_ptr<Subscription>> getSubscriptions() {
    return classQuery<Subscription>();
  }

  /**
   * \brief Creates an exchange with the given type and name
   * @param type
   * @param name
   * @param properties
   */
  void createExchange(Exchange::ExchangeType type, const std::string& name,
                      const std::map<std::string, std::string> properties = std::map<std::string, std::string>()) {
    typename VariantT::Map props;
    props.emplace("exchange-type", ExchangeTypeDesc::getExchangeTypeDesc(type));
    props.insert(properties.begin(), properties.end());

    typename VariantT::Map args;
    args.emplace("type", Exchange::OBJECT_TYPE_NAME);
    args.emplace("name", name);
    args.emplace("properties", props);
    args.emplace("strict", true);

    method<TrivialResponseType>("create", args);
  }

  /**
   * \brief Deletes an exchange with the given name
   * @throws RPCException if the exchange does not exist.
   * @param name
   */
  void deleteExchange(const std::string& name) {
    typename VariantT::Map args;
    args.emplace("type", Exchange::OBJECT_TYPE_NAME);
    args.emplace("name", name);

    method<TrivialResponseType>("delete", args);
  }

  /**
   * \brief Creates a queue with the given type and name
   * @param type
   * @param name
   * @param properties
   */
  void createQueue(const std::string& name,
                      const std::map<std::string, std::string> properties = std::map<std::string, std::string>()) {
    typename VariantT::Map props;
    props.insert(properties.begin(), properties.end());

    typename VariantT::Map args;
    args.emplace("type", Queue::OBJECT_TYPE_NAME);
    args.emplace("name", name);
    args.emplace("properties", props);
    args.emplace("strict", true);

    method<TrivialResponseType>("create", args);
  }
  /**
   * \brief Deletes a queue with the given name
   * @throws RPCException if the queue does not exist.
   * @param name
   */
  void deleteQueue(const std::string& name, bool if_empty, bool if_unused) {
    typename VariantT::Map options;
    options.emplace("if_empty", boost::lexical_cast<std::string>(if_empty));
    options.emplace("if_unused", boost::lexical_cast<std::string>(if_unused));

    typename VariantT::Map args;
    args.emplace("type", Queue::OBJECT_TYPE_NAME);
    args.emplace("name", name);
    args.emplace("options", options);

    method<TrivialResponseType>("delete", args);
  }

  /**
   * \brief Binds a queue to an exchange (both of which must exist) with the given binding key, which may be empty.
   * @param exchange_name
   * @param queue_name
   * @param key
   * @param properties
   */
  void bind(const std::string& exchange_name, const std::string& queue_name, const std::string& key,
            const std::map<std::string, std::string>& properties = std::map<std::string, std::string>()) {
    typename VariantT::Map props;
    props.insert(properties.begin(), properties.end());

    typename VariantT::Map args;
    args.emplace("type", Binding::OBJECT_TYPE_NAME);
    args.emplace("name", boost::str(boost::format("%s/%s/%s") % exchange_name % queue_name % key));
    args.emplace("properties", props);
    args.emplace("strict", true);

    method<TrivialResponseType>("create", args);
  }

  /**
   * \brief Removes a binding (which must exist) of a queue to an exchange with the given binding key.
   * @param exchange_name
   * @param queue_name
   * @param key
   */
  void unbind(const std::string& exchange_name, const std::string& queue_name, const std::string& key) {
    typename VariantT::Map args;
    args.emplace("type", Binding::OBJECT_TYPE_NAME);
    args.emplace("name", boost::str(boost::format("%s/%s/%s") % exchange_name % queue_name % key));
    args.emplace("strict", true);

    method<TrivialResponseType>("delete", args);
  }

  /**
   * \brief Requests that the broker reload its ACL file
   */
  void reloadACLFile() {
    typename VariantT::Map args;
    const std::string address = "org.apache.qpid.acl:acl:org.apache.qpid.broker:broker:amqp-broker";

    method<TrivialResponseType, typename VariantT::Map>("reloadACLFile", args, address);
  }

  void queueMoveMessages(const std::string& sourceQueue, const std::string& destQueue, size_t quantity) {
    typename VariantT::Map args;
    args.emplace("srcQueue", sourceQueue);
    args.emplace("destQueue", destQueue);
    args.emplace("qty", quantity);

    method("queueMoveMessages", args);
  }

  void queueRedirect(const std::string& sourceQueue, const std::string& destQueue) {
    typename VariantT::Map args;
    args.emplace("sourceQueue", sourceQueue);
    args.emplace("targetQueue", destQueue);

    method("queueRedirect", args);
  }

  void setLogLevel(const std::string& level) {
    typename VariantT::Map args;
    args.emplace("level", level);

    method("setLogLevel", args);
  }

  std::string getLogLevel() {
    typename VariantT::Map args;
    return method("getLogLevel", args);
  }

  /**
   * \brief No clue what this returns...
   * @param user
   * @param action
   * @param aclObj
   * @param aclObjName
   * @param args
   */
  AclLookupType aclLookup(const std::string& user, const std::string& action, const std::string& aclObj, const std::string& aclObjName,
                 const typename VariantT::Map& properties) {
    typename VariantT::Map args;
    args.emplace("userId", user);
    args.emplace("action", action);
    args.emplace("object", aclObj);
    args.emplace("objectName", aclObjName);
    args.emplace("propertyMap", properties);

    auto result = method<AclLookupType>("Lookup", args, "org.apache.qpid.acl:acl:org.apache.qpid.broker:broker:amqp-broker");

    return result ? *result.get() : "";
  }

  /**
   * \brief No clue what this returns...
   * @param user
   * @param exchange
   * @param key
   */
  AclLookupType aclLookupPublish(const std::string& user, const std::string& exchange, const std::string& key) {
    typename VariantT::Map args;
    args.emplace("userId", user);
    args.emplace("exchangeName", exchange);
    args.emplace("routingKey", key);

    auto result = method<AclLookupType>("LookupPublish", args, "org.apache.qpid.acl:acl:org.apache.qpid.broker:broker:amqp-broker");

    return result ? *result.get() : "";
  }

  /**
   * \brief Request a response to test the path to the management broker
   * @param sequence
   * @param body
   * @return
   */
  const std::shared_ptr<EchoType> echo(int sequence, const std::string& body = "Body") {
    typename VariantT::Map args;
    args.emplace("sequence", sequence);
    args.emplace("body", body);

    return method<EchoType>("echo", args);
  }

protected:
  static const std::string TARGET_ADDRESS;
  static const std::string TARGET_SUBJECT;

  std::shared_ptr<SessionT> session;
  int correlator; // Maybe use atomic int?

  /**
   * \brief Sends a message to the qmf exchange with the reply address set to replyAddress
   * @param message
   * @param replyAddress
   * @return the correlation id of the sent message
   */
  int sendMessage(MessageT &message, const AddressT &replyAddress) {
    auto sender = session->createSender(TARGET_ADDRESS + "/" + TARGET_SUBJECT);

    message.setReplyTo(replyAddress);

    auto local_correlator = ++correlator;
    message.setCorrelationId(std::to_string(local_correlator));

    // Routing key
    message.setSubject(TARGET_SUBJECT);

    sender.send(message, true);

    return local_correlator;
  }

  /**
   * \brief Awaits a complete response, which may span several messages.
   * The method template params Rep and Period refer to the types used by the calling application. It is assumed that
   * the class template parameter DurationT is of a different type and has a constructor which expects
   * a time interval in ms.
   * @param receiver
   * @param correlation_id
   * @param timeout
   * @return
   */
  template <typename Rep, typename Period>
  std::vector<MessageT> awaitResponse(ReceiverT &receiver, int correlation_id, std::chrono::duration<Rep, Period> timeout) {
    std::string local_correlation_id = std::to_string(correlation_id);

    std::vector<MessageT> messages;
    auto start = std::chrono::steady_clock::now();
    while (true) {
      auto local_timeout = timeout - (std::chrono::steady_clock::now() - start); // Some sneaky type-jiggery here
      if (local_timeout < std::chrono::duration<Rep, Period>::zero()) {
        // Throw timeout exception
        throw BrokerAgentException("Timeout waiting for qmf responses");
      }
      DurationT recv_timeout(std::chrono::duration_cast<std::chrono::milliseconds>(local_timeout).count());
      MessageT message;
      if (receiver.fetch(message, recv_timeout) && message.getCorrelationId() == local_correlation_id) {
        messages.push_back(message);

        // If the message contains the "partial" flag, there should be more message to read.
        // Empirical data suggests the broker transmits a maximum of 100 records per message.
        auto& properties = message.getProperties();
        if (properties.find("partial") == properties.end()) {
          break;
        }
        // Don't acknowledge the message here: it could be a message we want (in which case
        // we can acknowledge it later, when it's been processed) or there was a correlation mismatch
        // (in which case it has nothing to do with us).
      }
    }

    return messages;
  }

  ReceiverT createTemporaryReceiver() {
    const std::string RECEIVER_NODE_ARGS = ";{ create: always, node: { x-declare: { auto-delete: true }}}";

    boost::uuids::uuid uuid = boost::uuids::random_generator()();

    const std::string queue_address = boost::lexical_cast<std::string>(uuid) + RECEIVER_NODE_ARGS;

    return session->createReceiver(queue_address);
  }

  template <typename ObjectT, typename MapT>
  std::shared_ptr<ObjectT> method(const std::string& method_name, const MapT& arguments) {
    return method<ObjectT, MapT>(method_name, arguments, "org.apache.qpid.broker:broker:amqp-broker");
  }

  template <typename ObjectT, typename MapT>
  std::shared_ptr<ObjectT> method(const std::string& method_name, const MapT& arguments, const std::string& address) {
    auto receiver = createTemporaryReceiver();

    typename VariantT::Map object_id_map;
    object_id_map.emplace("_object_name", address);

    typename VariantT::Map query;
    query.emplace("_object_id", object_id_map);
    query.emplace("_arguments", arguments);
    query.emplace("_method_name", method_name);

    MessageT request;
    request.setProperty("x-amqp-0-10.app-id", "qmf2");
    request.setProperty("qmf.opcode", "_method_request");
    request.setProperty("method", "request");

    request.setContentObject(query);

    auto reply_to = receiver.getAddress();
    int correlation_id = sendMessage(request, reply_to);

    auto response = awaitResponse(receiver, correlation_id, std::chrono::seconds(10));
    return decodeMethodResponse<ObjectT>(response);
  }

  template <typename ObjectT>
  std::shared_ptr<ObjectT> decodeMethodResponse(const std::vector<MessageT>& response) {
    if (!response.empty()) {
      // Read the opcode off the first message
      const auto &message = response.front();
      std::string opcode = message.getProperties().at("qmf.opcode");
      if (opcode == "_exception") {
        throw codec::ExceptionDecoder<MessageT>().decodeException(message);

      } else if (opcode == "_query_response") {
        throw codec::DecodeException("A query response is unexpected here - use ResponseDecoder instead");

      } else if (opcode == "_method_response") {
        const auto& object_map = message.getContentObject().asMap();
        // std::cout << object_map << std::endl;
        return typename codec::decoder_traits<ObjectT, VariantT>::DecoderType().decode(object_map);

      } else { // opcode not recognised
        throw codec::DecodeException(boost::str(boost::format("Failed to decode response: %s") % message.getContent()));
      }
    } else {
      throw BrokerAgentException("No response received");
    }
  }

  template <typename MapT>
  int sendRequest(const std::string& opcode, const MapT& query, const AddressT& replyAddress) {
    MessageT request;
    request.setProperty("x-amqp-0-10.app-id", "qmf2");
    request.setProperty("qmf.opcode", opcode);

    request.setContentObject(query);

    return sendMessage(request, replyAddress);
  }

  template <typename ObjectType>
  std::vector<std::shared_ptr<ObjectType>> objectQuery(const std::string& schemaMetaId, const std::string& objectMetaId, const std::string& objectId) {
    auto receiver = createTemporaryReceiver();

    typename VariantT::Map schemaId;
    schemaId.emplace(objectMetaId, objectId);
    typename VariantT::Map query;
    query.emplace("_what", "OBJECT");
    query.emplace(schemaMetaId, schemaId);

    auto correlation_id = sendRequest("_query_request", query, receiver.getAddress());

    auto response = awaitResponse(receiver, correlation_id, std::chrono::seconds(10));
    return codec::ResponseDecoder<MessageT, ObjectType, VariantT>().decodeResponse(response);
  }

  template <typename ObjectType>
  std::vector<std::shared_ptr<ObjectType>> classQuery() {
    return objectQuery<ObjectType>("_schema_id", "_class_name", ObjectType::OBJECT_TYPE_NAME);
  }

  template <typename ObjectType>
  std::vector<std::shared_ptr<ObjectType>> nameQuery(const std::string& objectId) {
    return objectQuery<ObjectType>("_object_id", "_object_name", objectId);
  }

  template <typename ObjectType>
  const std::shared_ptr<ObjectType> getSingleObject() {
    auto objects = classQuery<ObjectType>();
    return objects.empty() ? std::shared_ptr<ObjectType>() : objects.front();
  }

  template <typename ObjectType>
  const std::shared_ptr<ObjectType> getObject(const std::string &name) {
    const std::string qpidName(boost::str(boost::format("org.apache.qpid.broker:%s:%s") % ObjectType::OBJECT_TYPE_NAME % name));

    auto objects = nameQuery<ObjectType>(qpidName);

    // Return the first node or a null shared_ptr
    return objects.empty() ? std::shared_ptr<ObjectType>() : objects.front();
  }
};

template<typename AddressT, typename SessionT, typename ReceiverT, typename MessageT, typename DurationT, typename VariantT>
const std::string BrokerAgentTemplate<AddressT, SessionT, ReceiverT, MessageT, DurationT, VariantT>::TARGET_ADDRESS = std::string("qmf.default.direct");
template<typename AddressT, typename SessionT, typename ReceiverT, typename MessageT, typename DurationT, typename VariantT>
const std::string BrokerAgentTemplate<AddressT, SessionT, ReceiverT, MessageT, DurationT, VariantT>::TARGET_SUBJECT = std::string("broker");

}} // Namespaces

#endif //FOURC_FMF_BROKERAGENTTEMPLATE_H
