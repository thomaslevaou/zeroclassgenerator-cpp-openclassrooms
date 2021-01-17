#include "FenPrincipale.h"

FenPrincipale::FenPrincipale(FenCodeGenere *fenetreCodeGenere) : QWidget()
{
  this->setWindowIcon(QIcon("icone.png"));
  this->setWindowTitle("Zero Class Generator");

  m_layoutPrincipal = new QVBoxLayout;

    // Formulaire "Définition de la classe"
    m_definitionClasse = new QGroupBox("Définition de la classe");
      m_formDefinitionClasse = new QFormLayout;
        m_nom = new QLineEdit();
        m_classeMere = new QLineEdit();
        m_formDefinitionClasse->addRow("&Nom", m_nom);
        m_formDefinitionClasse->addRow("Classe &mère", m_classeMere);
      m_definitionClasse->setLayout(m_formDefinitionClasse);
    m_layoutPrincipal->addWidget(m_definitionClasse);

    // Formulaire "Options"
    m_options = new QGroupBox("Options");
      m_optionsLayout = new QVBoxLayout;
        m_doubleInclusionProtection = new QCheckBox("Protéger le &header contre les inclusions multiples");
        m_doubleInclusionProtection -> setChecked(true);
        m_generateDefaultConstructor = new QCheckBox("Générer un &constructeur par défaut");
        m_generateDefaultConstructor -> setChecked(true);
        m_generateDestructor = new QCheckBox("Générer un &destructeur");
        m_optionsLayout->addWidget(m_doubleInclusionProtection);
        m_optionsLayout->addWidget(m_generateDefaultConstructor);
        m_optionsLayout->addWidget(m_generateDestructor);
      m_options->setLayout(m_optionsLayout);
    m_layoutPrincipal->addWidget(m_options);

    // Formulaire "Ajouter des commentaires"
    m_commentaires = new QGroupBox("Ajouter des commentaires");
    // Les champs du groupbox seront actifs si la case est cochée seulement
    m_commentaires->setCheckable(true);
      m_commentairesForm = new QFormLayout;
        m_auteur = new QLineEdit();
        // y, m, d en paramètres du constructeur de QDate
        m_creationDate = new QDateEdit(QDate(2020, 07, 30));
        m_classRole = new QTextEdit();
        m_commentairesForm -> addRow("&Auteur", m_auteur);
        m_commentairesForm -> addRow("Da&te de création", m_creationDate);
        m_commentairesForm -> addRow("&Rôle de la classe", m_classRole);
      m_commentaires -> setLayout(m_commentairesForm);
    m_layoutPrincipal -> addWidget(m_commentaires);

    // Boutons du bas du formulaire
    m_bottomButtonLayout = new QHBoxLayout;
    // addStretch permet de "démarrer les boutons par la fin"
    m_bottomButtonLayout -> addStretch();
      m_generateButton = new QPushButton("Générer !");
      QWidget::connect(m_generateButton, SIGNAL(clicked()), this, SLOT(emitCodeGenere()));
      QObject::connect(this, SIGNAL(codeToSend(QString)), fenetreCodeGenere, SLOT(afficherCode(QString)));
      m_bottomButtonLayout -> addWidget(m_generateButton);
      m_quitButton = new QPushButton("Quitter");
      QObject::connect(m_quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
      m_bottomButtonLayout -> addWidget(m_quitButton);
    m_layoutPrincipal -> addLayout(m_bottomButtonLayout);


  this->setLayout(m_layoutPrincipal);
}


void FenPrincipale::emitCodeGenere()
{
  QString codeAafficher("");

  if (m_commentaires -> isChecked()) {
    codeAafficher += "/* \n";
    if (m_auteur->text() != "") {
      codeAafficher += "Auteur : " + m_auteur->text() + "\n";
    }
    if (m_creationDate->text() != "") {
      codeAafficher += "Date de création : " + m_creationDate->date().toString() + "\n";
    }
    /* Gère un personnage de type "Magicien".
        Peut être spécialisé en :
        - MagicienBlanc
        - MagicienNoir */
    if (m_classRole->toPlainText() != "") {
      codeAafficher += "\nRôle : \n" + m_classRole->toPlainText() + "\n";
    }
    codeAafficher += "*/ \n\n\n";
  }

  if (m_doubleInclusionProtection->isChecked()) {
    codeAafficher += "#ifndef HEADER_" + m_nom->text().toUpper() + "\n";
    codeAafficher += "#define HEADER_" + m_nom->text().toUpper() + "\n";
  }

  if (m_nom -> text() != "") {
    codeAafficher += "\nclass " + m_nom->text();

    if (m_classeMere->text() != "") {
      codeAafficher += " : public " + m_classeMere->text();
    }
    codeAafficher += "\n{\n\tpublic:\n";
    if (m_generateDefaultConstructor->isChecked()) {
      codeAafficher += "\t\t" + m_nom->text() + "();\n";
    }
    if (m_generateDestructor->isChecked()) {
      codeAafficher += "\t\t~" + m_nom->text() + "();\n";
    }
    codeAafficher += "\n\tprotected:\n";
    codeAafficher += "\n\tprivate:\n";
    codeAafficher += "\n}\n";
  }

  if (m_doubleInclusionProtection->isChecked()) {
    codeAafficher += "\n#endif";
  }
  emit codeToSend(codeAafficher);
}
