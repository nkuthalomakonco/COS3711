#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>

class Registration;


class TableModel: public QAbstractTableModel
{
public:
    TableModel(QObject *parent=0);
    TableModel(QList<Registration*>,QObject *parent=0);
    ~TableModel();
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
   // bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
   // bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    void clear();
    bool addRegistration(Registration *reg);
    void setList(QList<Registration*> &l);
    QList<Registration*> getList()const;
    double getTotalFee(QString type)const;
    bool contains(Registration *reg)const;

private:
    QList<Registration*> list;
    QStringList headers = {"Name","Affiliation","Email","Fee","Date","Catergory","Qualification","Registration"};
};

#endif // TABLEMODEL_H
