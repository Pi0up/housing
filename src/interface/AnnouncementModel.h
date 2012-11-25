#ifndef ANNOUNCEMENTMODEL_H
#define ANNOUNCEMENTMODEL_H

#include <QAbstractTableModel>

#include "Announcement.h"

class AnnouncementModelPrivate;

class AnnouncementModel : public QAbstractTableModel
{
    Q_OBJECT
    
public:
    enum CustomRoles {
        IdRole = Qt::UserRole,
        IgnoredRole,
        BookmarkedRole,
        UrlRole,
        AnnouncementRole,
        // internal, do not use
        FirstRole = IdRole,
        LastRole = AnnouncementRole
    };
    
    AnnouncementModel( QObject* parent = 0 );
    virtual ~AnnouncementModel();
    
    virtual int columnCount( const QModelIndex& parent = QModelIndex() ) const;
    virtual int rowCount( const QModelIndex& parent = QModelIndex() ) const;
    virtual QVariant data( const QModelIndex& index, int role = Qt::DisplayRole ) const;
    virtual QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
    virtual void sort( int column, Qt::SortOrder order = Qt::AscendingOrder );
    
    void clear();
    void addAnnouncements( const Announcement::List& announcements );
    void addAnnouncement( const Announcement& announcement );
    void setAnnouncements( const Announcement::List& announcements );
    void removeAnnouncements( const QModelIndexList& indexes );
    void removeAnnouncement( const QModelIndex& index );
    Announcement::List announcements() const;
    Announcement announcement( const QModelIndex& index ) const;
    
    void setIgnoredIdSet( const QSet<int> ids );
    QSet<int> ignoredIdSet() const;
    
    void setBookmarkedIdSet( const QSet<int> ids );
    QSet<int> bookmarkedIdSet() const;

public slots:
    void update();

private:
    AnnouncementModelPrivate* d;

signals:
    void requestImageDownload( const QString& url );
};

#endif // ANNOUNCEMENTMODEL_H
