#include "Task.hh"

Task::Task(QObject *p) : QObject(p) {}

Task::Task(const QString &name, const std::vector<Task::interval_t> &timeSpend, QObject *p) :
    QObject(p), name_(name), intervals_(timeSpend)
{
    seconds_ = std::accumulate(intervals_.cbegin(), intervals_.cend(), 0,
                               [](uint32_t val, const interval_t &i) {
        return val + i.second;
    });
}

const QString &Task::name() const
{
    return name_;
}

uint32_t Task::days() const noexcept
{
    return intervals_.size();
}

uint32_t Task::allTimeSpent() const noexcept
{
    return seconds_;
}
