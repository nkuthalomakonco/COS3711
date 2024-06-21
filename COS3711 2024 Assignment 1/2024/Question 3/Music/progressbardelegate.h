#ifndef PROGRESSBARDELEGATE_H
#define PROGRESSBARDELEGATE_H

#include <QStyledItemDelegate>
/*
Use a delegate to display the rating as a horizontal bar. This column should take up all the remaining space available.
*/
class ProgressBarDelegate: public QStyledItemDelegate
{
    Q_OBJECT
public:
    ProgressBarDelegate(QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // PROGRESSBARDELEGATE_H
