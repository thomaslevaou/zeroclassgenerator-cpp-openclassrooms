#ifndef DEF_FENPRINCIPALE
#define DEF_FENPRINCIPALE

#include <QApplication>
#include <QtWidgets>
#include "FenCodeGenere.h"

class FenPrincipale : public QWidget
{
    Q_OBJECT

    public:
      FenPrincipale(FenCodeGenere *fenetreCodeGenere);

    public slots:
      void emitCodeGenere();

    signals:
      void codeToSend(QString codeAafficher);

    private:
      QVBoxLayout *m_layoutPrincipal;

        QGroupBox *m_definitionClasse;
          QFormLayout *m_formDefinitionClasse;
            QLineEdit *m_nom;
            QLineEdit *m_classeMere;

        QGroupBox *m_options;
          QVBoxLayout *m_optionsLayout;
            QCheckBox *m_doubleInclusionProtection;
            QCheckBox *m_generateDefaultConstructor;
            QCheckBox *m_generateDestructor;

        QGroupBox *m_commentaires;
          QFormLayout *m_commentairesForm;
            QLineEdit *m_auteur;
            QDateEdit *m_creationDate;
            QTextEdit *m_classRole;

        QHBoxLayout *m_bottomButtonLayout;
          QPushButton *m_generateButton;
          QPushButton *m_quitButton;
};

#endif
