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


struct FileInfo {
    QString Name;
    QString AbsolutePath;
};
FileInfo FI;
QVector <FileInfo> ArrFI;

class SCore
{
public:
    SCore();
    bool setVar(char Var = 'X', QString Val = "X" );
    QString getVar(char Var = 'X');
    bool writeVectorDir (QString Dir);
private:
    QString DirOut;
    QString DirExt;
    QString Dirlcl;

};

#endif // SCORE_H
