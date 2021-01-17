#include "FenCodeGenere.h"


FenCodeGenere::FenCodeGenere() : QDialog() {
  m_layoutPrincipal = new QVBoxLayout;
    m_codeGenere = new QTextEdit();
    m_codeGenere->setFont(QFont("Courier"));
    m_codeGenere -> setReadOnly(true);
    m_layoutPrincipal -> addWidget(m_codeGenere);
    m_boutonFermer = new QPushButton("Fermer");
    QObject::connect(m_boutonFermer, SIGNAL(clicked()), this, SLOT(close()));
    m_layoutPrincipal -> addWidget(m_boutonFermer);

  this->setLayout(m_layoutPrincipal);
}

void FenCodeGenere::afficherCode(QString codeAafficher) {
    m_codeGenere->setPlainText(codeAafficher);
    exec();
}
