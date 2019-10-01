//#ifndef DOCUMENTHANDLER_H
//#define DOCUMENTHANDLER_H

//#include <QObject>

//class DocumentHandler : public QObject
//{
//    Q_OBJECT
//public:
//    explicit DocumentHandler(QObject *parent = 0);

//signals:

//public slots:

//};

//#endif // DOCUMENTHANDLER_H




#ifndef DOCUMENTHANDLER_H
#define DOCUMENTHANDLER_H

#include <QQuickTextDocument>

#include <QtGui/QTextCharFormat>
#include <QtCore/QTextCodec>

#include <qqmlfile.h>

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

class DocumentHandler : public QObject
{
    Q_OBJECT
    Q_ENUMS(HAlignment)

    Q_PROPERTY(QQuickItem *target READ target WRITE setTarget NOTIFY targetChanged)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QUrl fileUrl READ fileUrl WRITE setFileUrl NOTIFY fileUrlChanged)
    Q_PROPERTY(QString documentTitle READ documentTitle WRITE setDocumentTitle NOTIFY documentTitleChanged)

public:
    DocumentHandler();

    QQuickItem *target(){ return m_target;}
    QUrl fileUrl() const;
    QString text() const;
    void setTarget(QQuickItem *target);
    QString documentTitle() const;

public Q_SLOTS:

    void setFileUrl(const QUrl &arg);
    void setText(const QString &arg);
    void save(const QUrl &arg);
    void saveAs(const QUrl &arg, const QString &fileType);
    void setDocumentTitle(QString arg);

Q_SIGNALS:

    void fileUrlChanged();
    void documentTitleChanged();
    void textChanged();
    void error(QString message);
    void targetChanged();

private:
    void reset();

    QQuickItem *m_target;
    QTextDocument *m_doc;

    QUrl m_fileUrl;
    QString m_text;
    QString m_documentTitle;
};

#endif
