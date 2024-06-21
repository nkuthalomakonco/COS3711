#include "progressbardelegate.h"
#include "qpainter.h"

#include <QApplication>
////https://github.com/lpxxn/QTableViewAddProgressBar
ProgressBarDelegate::ProgressBarDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}
void ProgressBarDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int progress = index.model()->data(index).toString().replace("%", "").toInt();
    if(progress < 0) progress = 0;
    if(progress > 100) progress = 100;
    QStyleOptionProgressBar progressBarOption;
    progressBarOption.rect = option.rect; //option.rect.adjusted(4, 4, -4, -4);
    progressBarOption.minimum = 0;
    progressBarOption.maximum = 100;
    progressBarOption.progress = progress;
    progressBarOption.textAlignment = Qt::AlignCenter;
    progressBarOption.text = QString::number(progress) + "%";
    progressBarOption.textVisible = true;

    QApplication::style()->drawControl(QStyle::CE_ProgressBar,
                                       &progressBarOption, painter);
}

/*
 * Both methods perform the same function.
 * */

//void ProgressBarDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
//{

//    if (index.data().canConvert<int>())
//    {
//        QRect bar = QRect(option.rect.topLeft(), QSize(option.rect.width()*(index.data().toInt())/100.0, option.rect.height()));
//        painter->fillRect(option.rect, option.palette.dark());
//        painter->fillRect(bar, option.palette.highlight());
//    }
//    else
//        QStyledItemDelegate::paint(painter, option, index);
//}

