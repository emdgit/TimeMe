#pragma once

#include <QObject>
#include <QDate>

#include <vector>

class Task : public QObject
{

    Q_OBJECT

public:

    /// Pair of Date and its time spent in seconds.
    using interval_t = std::pair<QDate, uint32_t>;

    explicit Task(QObject *p = nullptr);

    Task(const QString &name,
         const std::vector<interval_t> &timeSpend,
         QObject *p = nullptr);


    /// Return Task's name.
    const QString &name() const;

    /// Return amount of days.
    uint32_t days() const noexcept;

    /// Return sum of all time spent.
    uint32_t allTimeSpent() const noexcept;


private:

    /// Task's name.
    QString name_;

    /// Intervals spent.
    std::vector<interval_t> intervals_;

    /// Calculated full interval in seconds.
    uint32_t seconds_ = 0;

};


