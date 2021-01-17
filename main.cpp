#include <QApplication>
#include "FenPrincipale.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FenCodeGenere fenetreCodeGenere;
    FenPrincipale fenetre(&fenetreCodeGenere);
    fenetre.show();

    return app.exec();
}
