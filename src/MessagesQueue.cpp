#include "MessagesQueue.hpp"

namespace {
    static uint64_t id = 0;
}

uint64_t nextId() {
    return id++;
}

uint64_t& totalCounter() {
    return id;
}

Message::Message(const uint64_t id, const std::string &dest_, const std::string &message_) :
        dest_(dest_), message_(message_), id_(id) {}

Message::Message(const std::string &dest_, const std::string &message_) :
        dest_(dest_), message_(message_), id_(nextId()) {}

std::string Message::dest() const {
    return dest_;
}

std::string Message::message() const {
    return message_;
}

uint64_t Message::id() const {
    return id_;
}


void MessagesQueue::addMessage(const Message & m) {
    messagesContainer_[m.dest()].push(m);
}

bool MessagesQueue::hasNext(const std::string &user) const {
    return messagesContainer_.count(user) && !messagesContainer_.at(user).empty();
}

Message MessagesQueue::getNext(const std::string &user) {
    Message res(messagesContainer_[user].front());
    messagesContainer_[user].pop();
    return res;
}

MessagesQueue::MessagesQueue() { }

void MessagesQueue::clear() {
    messagesContainer_.clear();
}


template<>
MessagesQueue& singleton() {
    static MessagesQueue mq;
    return mq;
}



void clearMessageQueue() {
    id = 0;
    auto& mq = singleton<MessagesQueue>();
    mq.clear();
}