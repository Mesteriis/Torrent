#ifndef SCORE_H
#define SCORE_H
#include <QString>
#include <QVector>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QTimer>
#include <QTime>

#include <QStandardPaths>
#include <QStringList>
#include <QDebug>




class SCore
{
public:
    SCore();

    struct FileInfo {
        QString Name;
        QString AbsolutePath;
    };
    FileInfo FI;
    QVector <FileInfo> ArrFI;

    bool setVar(char Var = 'd', QString Val = "defaunt" );
    QString getVar(char Var = 'd');
    bool writeVectorDir (QString Dir);

    bool moveTorFile (QString nameOut, char pathIn = 'e');

private:
    QString DirOut;
    QString DirExt;
    QString Dirlcl;

};

#endif // SCORE_H
