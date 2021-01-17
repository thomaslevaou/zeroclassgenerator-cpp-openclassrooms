#ifndef DEF_FENCODEGENERE
#define DEF_FENCODEGENERE

#include <QApplication>
#include <QtWidgets>

class FenCodeGenere : public QDialog
{
    Q_OBJECT

    public:
      /* On pourrait aussi faire comme la correction et mettre une fenêtre parent, en créant un deuxième
      * paramètre qui vaudra this dans la fenêtre parent.
      * On appellerait dans ce cas exec() directement dans la fenêtre parent */
      FenCodeGenere();

    public slots:
      void afficherCode(QString codeAafficher);

    private:
      QVBoxLayout *m_layoutPrincipal;
        QTextEdit *m_codeGenere;
        QPushButton *m_boutonFermer;
};

#endif
