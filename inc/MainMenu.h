#pragma once

#include "SheetFractal.h"
#include "FirFractal.h"

namespace fg {
    class MainMenu : public QWidget {
    Q_OBJECT
    private:
        QPushButton *m_btnSheetFractal;
        QPushButton *m_btnFirFractal;
        QPushButton *m_btnMyFractal;
        QPushButton *m_btnClose;
        QLabel *m_Title;
        std::unique_ptr<SheetFractal> m_sheetFractal;
        std::unique_ptr<FirFractal> m_firFractal;

    public:
        explicit MainMenu(QWidget *pwgt = nullptr) : QWidget(pwgt) {
            this->resize(400, 300);
            this->setMinimumSize(QSize(400, 300));
            this->setMaximumSize(QSize(400, 300));

            m_btnSheetFractal = new QPushButton(this);
            m_btnSheetFractal->setGeometry(QRect(100, 90, 200, 24));
            m_btnFirFractal = new QPushButton(this);
            m_btnFirFractal->setGeometry(QRect(100, 130, 200, 24));
            m_btnMyFractal = new QPushButton(this);
            m_btnMyFractal->setGeometry(QRect(100, 170, 200, 24));
            m_btnClose = new QPushButton(this);
            m_btnClose->setGeometry(QRect(100, 210, 200, 24));
            m_Title = new QLabel(this);
            m_Title->setGeometry(QRect(0, 10, 401, 71));
            QFont font;
            font.setFamilies({QString::fromUtf8("Impact")});
            font.setPointSize(20);
            m_Title->setFont(font);
            m_Title->setAlignment(Qt::AlignCenter);

            setText();

            connect(m_btnSheetFractal, SIGNAL(clicked()), SLOT(slotBtnOpenSheetFractal()));
            connect(m_btnFirFractal, SIGNAL(clicked()), SLOT(slotBtnOpenFirFractal()));
            connect(m_btnClose, SIGNAL(clicked()), SLOT(close()));
        }

        ~MainMenu() = default;

    private:
        void setText() {
            this->setWindowTitle(QString::fromUtf8("Fractal Generator 2"));
            m_btnSheetFractal->setText(QString::fromUtf8("Лист папоротника"));
            m_btnFirFractal->setText(QString::fromUtf8("Елка"));
            m_btnMyFractal->setText(QString::fromUtf8("Шоу \"эксперименты\""));
            m_btnClose->setText(QString::fromUtf8("Закрыть программу"));
            m_Title->setText(QString::fromUtf8("Fractal Generator"));
        }

    private slots :

        void slotBtnOpenSheetFractal() {
            m_sheetFractal = std::make_unique<SheetFractal>("Лист папоротника");
            m_sheetFractal->show();
        };

        void slotBtnOpenFirFractal(){
            m_firFractal = std::make_unique<FirFractal>("Ёлочка");
            m_firFractal->show();
        }
    };
}