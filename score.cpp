#include "score.h"

SCore::SCore()
{

}

bool SCore::setVar(char Var, QString Val)
{
    QStringList homePath = QStandardPaths::standardLocations(QStandardPaths::HomeLocation);
    QString TMP =  homePath.first().split(QDir::separator()).last();

    switch (Var) {
    case 'e':
        DirExt = Val;
        break;
    case 'o':
        DirOut = Val;
        break;
    case 'l':
        Dirlcl = Val;
        break;
    default:
        DirOut = "/Users/" + TMP + "/Downloads";

        // стандарт
        DirExt = "/Users/" + TMP + "/Library/Mobile Documents/com~apple~CloudDocs/Tor_Links";
        Dirlcl = "/Users/" + TMP + "/Downloads/torrent/TorFiles";

//        DirExt = "/Users/" + TMP + "/Downloads/1";
//        Dirlcl = "/Users/" + TMP + "/Downloads/1";
        break;
    }
    return true;
}

QString SCore::getVar(char Var)
{
    QString ans;
    switch (Var)
    {
        case 'e':
            return DirExt; // = "/Users/" + TMP + "/Library/Mobile Documents/com~apple~CloudDocs/Tor_Links";
            break;
        case 'l':
            return Dirlcl; // = "/Users/" + TMP + "/Downloads/torrent/TorFiles";
            break;
        default:
            return DirOut; // = "/Users/" + TMP + "/Downloads";
            break;
    }

    return ans;
}

bool SCore::writeVectorDir(QString Dir)
{
    QDir dir(Dir);
    QStringList nameFilter;
    nameFilter << "*.torrent";
    QFileInfoList list = dir.entryInfoList( nameFilter, QDir::Files );
    QFileInfo fileinfo;
    for (int i = 0; i < list.size(); ++i)
        {
            fileinfo                = list.at(i);
            SCore::FI.Name          = fileinfo.completeBaseName();
            SCore::FI.AbsolutePath  = fileinfo.absoluteFilePath();

            SCore::ArrFI.push_back(SCore::FI);
        }
    return true;
}

bool SCore::moveTorFile(QString nameOut, char pathIn)
{
    switch (pathIn)
    {
        case 'l':
            if(QFile::copy(SCore::getVar() + "/" + nameOut + ".torrent", SCore::getVar('l') + "/" + nameOut + ".torrent"))
            {
                QFile::remove(SCore::getVar() + "/" + nameOut + ".torrent");
            } else return false;
                break;
        case 'e':
            if(QFile::copy(SCore::getVar() + "/" + nameOut + ".torrent", SCore::getVar('e') + "/" + nameOut + ".torrent"))
            {
                QFile::remove(SCore::getVar() + "/" + nameOut + ".torrent");
            }else return false;
                break;
        default:
            int t=0;
            if (QFile::copy(SCore::getVar() + "/" + nameOut + ".torrent", SCore::getVar('e') + "/" + nameOut + ".torrent")) t++;
            if (QFile::copy(SCore::getVar() + "/" + nameOut + ".torrent", SCore::getVar('l') + "/" + nameOut + ".torrent")) t++;
            if (t==2)
            {
                QFile::remove(SCore::getVar() + "/" + nameOut + ".torrent");
            } else return false;
                break;
    }
    return true;
}
