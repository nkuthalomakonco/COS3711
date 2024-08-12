#include "tablemodel.h"
#include "registration.h"
#include "studentregistration.h"
#include "guestsregistration.h"


#include <QMetaProperty>

TableModel::TableModel(QObject *parent)
: QAbstractTableModel(parent)
{

}

TableModel::TableModel(QList<Registration *> l, QObject *parent)
    : list(l),QAbstractTableModel(parent)
{

}

TableModel::~TableModel()
{
    qDeleteAll(list);
    list.clear();
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return list.size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return headers.size();
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }
    if (role == Qt::TextAlignmentRole) {}

    int col = index.column();
    int row = index.row();

    Registration *obj = list.at(row);
    //const QMetaObject* metaObject = obj->metaObject();
    QString classname = QString::fromLatin1(obj->metaObject()->className());

   // if (role == Qt::DisplayRole || role == Qt::EditRole)
    if (role == Qt::DisplayRole)
    {
        if(classname == "StudentRegistration"){
           StudentRegistration * sr = qobject_cast<StudentRegistration*>(obj);
            switch(col) {
            case 0:
                return list.at(row)->getAttendee().getName();
                break;
            case 1:
                return list.at(row)->getAttendee().getAffiliation();
                break;
            case 2:
                return list.at(row)->getAttendee().getEmail();
                break;
            case 3:
                return QString::number(sr->calculateFee(), 'f', 2);
                break;
            case 4:
                return list.at(row)->getBookingDate().toString("dd/MM/yyyy");
                break;
            case 5:
                return QVariant(QString("none"));//catergory
                break;
            case 6:
                return sr->Qualification();//qualification
                break;
            case 7:
                return classname;//type
                break;
            default:
                break;
            }
        }else if (classname == "GuestsRegistration"){
            GuestsRegistration * gr = qobject_cast<GuestsRegistration*>(obj);
            switch(col) {
            case 0:
                return list.at(row)->getAttendee().getName();
                break;
            case 1:
                return list.at(row)->getAttendee().getAffiliation();
                break;
            case 2:
                return list.at(row)->getAttendee().getEmail();
                break;
            case 3:
                return QString::number(gr->calculateFee(), 'f', 2);
                break;
            case 4:
                return list.at(row)->getBookingDate().toString("dd/MM/yyyy");
                break;
            case 5:
                return gr->Catergory();//catergory
                break;
            case 6:
                return QVariant(QString("none"));//qualification
                break;
            case 7:
                return classname;//type
                break;
            default:
                break;
            }
        }else if(classname == "Registration"){
           Registration * r = qobject_cast<Registration*>(obj);
            (void)r;
           switch(col) {
           case 0:
               return list.at(row)->getAttendee().getName();
               break;
           case 1:
               return list.at(row)->getAttendee().getAffiliation();
               break;
           case 2:
               return list.at(row)->getAttendee().getEmail();
               break;
           case 3:
               return QString::number(list.at(row)->calculateFee(), 'f', 2);
               break;
           case 4:
               return list.at(row)->getBookingDate().toString("dd/MM/yyyy");
               break;
           case 5:
               return QVariant(QString("none"));//catergory
               break;
           case 6:
               return QVariant(QString("none"));//qualification
               break;
           case 7:
               return classname;//type
               break;
           default:
               break;
           }
        }else return QVariant();

    }

    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
            return QVariant();

    if (orientation == Qt::Vertical)
            return QVariant();

    switch (section)
    {
    case 0: return QString(headers.at(0)); break;
    case 1: return QString(headers.at(1)); break;
    case 2: return QString(headers.at(2)); break;
    case 3: return QString(headers.at(3)); break;
    case 4: return QString(headers.at(4)); break;
    case 5: return QString(headers.at(5)); break;
    case 6: return QString(headers.at(6)); break;
    case 7: return QString(headers.at(7)); break;
    default: return QVariant();
    }

    return QVariant();
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
            return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index);
    //return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid()) {
            int col = index.column();
            int row = index.row();

            auto *obj = list.at(row);
            QString classname = QString::fromLatin1(obj->metaObject()->className());
            if (role == Qt::EditRole || role == Qt::DisplayRole) {

            switch(col) {
            case 0:
               // list.at(row)->getAttendee().setName(value.toString());
                break;
            case 1:
              //  list.at(row)->getAttendee().setAffiliation(value.toString());
                break;
            case 2:
               // list.at(row)->getAttendee().setEmail(value.toString());
                break;
            case 3:
              //  list.at(row)->setSTANDARD_FEE(value.toDouble());
                break;
            case 4:
               // list.at(row)->setBookingDate(value.toDate());//QDate::fromString("11/11/2000","dd/MM/yyyy");
                break;
            case 5://catergory

                break;
            case 6://qualification

                break;
            case 7:
                 //list.at(row)->setObjectName(classname);
                break;
            default:
                return false;
            }//end switch
            }//end if

            emit dataChanged(index, index);
            return true;
    }

    return false;
}

void TableModel::clear()
{
    int row = list.size();
    if(row > 0){
            beginRemoveRows(QModelIndex(), 0, row-1);
            qDeleteAll(list);
            list.clear();
            endRemoveRows();
    }
}

bool TableModel::addRegistration(Registration *reg)
{
    int row = list.size();
    if(contains(reg)) qDebug() << "contains.";//return false.
    beginInsertRows(QModelIndex(), row, row);
    list.append(reg);
    endInsertRows();
    return true;
}

void TableModel::setList(QList<Registration *> &l)
{
    // Clear  list
    clear();
    foreach (auto r, l) {
            // Do not append null object
            if (r != nullptr) addRegistration(r);}

}

QList<Registration *> TableModel::getList() const
{
    return list;
}

double TableModel::getTotalFee(QString type) const
{
    double total = 0;

    if(type == "all") {
            for(int pos = 0; pos< list.size(); pos++){

//            Registration *obj = list.at(pos);
//            const QMetaObject* metaObject = obj->metaObject();
//            QString classname = QString::fromLatin1(obj->metaObject()->className());

            total+= list.at(pos)->calculateFee();
            } return total;
    }
    if(type == "students"){
            for(int pos = 0; pos< list.size(); pos++){
            auto * sr = qobject_cast<StudentRegistration*>(list.at(pos));
            if(sr) qDebug() << sr->toString();
            if(sr) total+= list.at(pos)->calculateFee();
            } return total;
    }
    if(type == "guests") {
            for(int pos = 0; pos< list.size(); pos++){
            auto * gr = qobject_cast<GuestsRegistration*>(list.at(pos));
            if(gr) qDebug() << gr->toString();
            if(gr) total+= list.at(pos)->calculateFee();
            } return total;
    }
    if(type == "standard") {
            for(int pos = 0; pos< list.size(); pos++){
            auto *obj = list.at(pos);
            QString classname = QString::fromLatin1(obj->metaObject()->className());
            if(classname.compare("Registration")==0) total+= list.at(pos)->calculateFee();
            } return total;
    }
    return total;
}
/*
 No two registrations are allowed to have attendees with the same e-mail addresses, unless the names are different.
 */
bool TableModel::contains(Registration *reg) const
{
    if(list.isEmpty()) return false;
    for(int pos = 0; pos< list.size(); pos++){
            bool c = (list.at(pos)->getAttendee().getName() == reg->getAttendee().getName()) && (list.at(pos)->getAttendee().getEmail() == reg->getAttendee().getEmail());
            if(c){
            return true;
            }
    }
    return false;
}



