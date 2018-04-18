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
        DirExt = "/Users/" + TMP + "/Library/Mobile Documents/com~apple~CloudDocs/Tor_Links";
        break;
    case 'o':
        DirOut = "/Users/" + TMP + "/Downloads";
        break;
    case 'l':
        Dirlcl = "/Users/" + TMP + "/Downloads/torrent/TorFiles";
        break;
    default:
        DirOut = "/Users/" + TMP + "/Downloads";
        DirExt = "/Users/" + TMP + "/Library/Mobile Documents/com~apple~CloudDocs/Tor_Links";
        Dirlcl = "/Users/" + TMP + "/Downloads/torrent/TorFiles";
        break;
    }
    return true;
}

QString SCore::getVar(char Var)
{
    QString ans;

    return ans;
}

bool SCore::writeVectorDir(QString Dir)
{
    return true;
}
