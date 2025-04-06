#include "MessageThreadChecker.h"
#include <juce_events/juce_events.h>

namespace EA
{
struct MessageThreadChecker : juce::DeletedAtShutdown
{
    MessageThreadChecker()
    {
        auto func = [this]
        { messageThreadID.store(juce::Thread::getCurrentThreadId()); };

        juce::MessageManager::getInstance()->callAsync(func);
    }

    bool isMessageThread() const noexcept
    {
        return juce::Thread::getCurrentThreadId() == messageThreadID.load();
    }

    ~MessageThreadChecker() override { clearSingletonInstance(); }

    JUCE_DECLARE_SINGLETON(MessageThreadChecker, false)

    std::atomic<juce::Thread::ThreadID> messageThreadID {nullptr};
};

JUCE_IMPLEMENT_SINGLETON(MessageThreadChecker)

bool isThisTheMessageThread()
{
    return MessageThreadChecker::getInstance()->isMessageThread();
}

struct MessageThreadCheckerInitializer
{
    MessageThreadCheckerInitializer() { MessageThreadChecker::getInstance(); }
};

MessageThreadCheckerInitializer m;
} // namespace EA
