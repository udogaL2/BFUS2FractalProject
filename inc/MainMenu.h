#pragma once

#include "SheetFractal.h"
#include "FirFractal.h"
#include "ExperimentFractal.h"
#include "MapleFractal.h"
#include "SpiralFractal.h"

namespace fg {
    class MainMenu : public QWidget {
    Q_OBJECT
    private:
        QPushButton *m_btnSheetFractal;
        QPushButton *m_btnFirFractal;
        QPushButton *m_btnMapleFractal;
        QPushButton *m_btnSpiralFractal;
        QPushButton *m_btnMyFractal;
        QPushButton *m_btnClose;
        QLabel *m_Title;
        std::unique_ptr<SheetFractal> m_sheetFractal;
        std::unique_ptr<FirFractal> m_firFractal;
        std::unique_ptr<MyFractal> m_myFractal;
        std::unique_ptr<MapleFractal> m_mapleFractal;
        std::unique_ptr<SpiralFractal> m_spiralFractal;

    public:
        explicit MainMenu(QWidget *pwgt = nullptr) : QWidget(pwgt) {
            this->resize(400, 400);
            this->setMinimumSize(QSize(400, 400));
            this->setMaximumSize(QSize(400, 400));

            m_btnSheetFractal = new QPushButton(this);
            m_btnSheetFractal->setGeometry(QRect(100, 90, 200, 24));
            m_btnFirFractal = new QPushButton(this);
            m_btnFirFractal->setGeometry(QRect(100, 130, 200, 24));
            m_btnMyFractal = new QPushButton(this);
            m_btnMyFractal->setGeometry(QRect(100, 280, 200, 24));
            m_btnMapleFractal = new QPushButton(this);
            m_btnMapleFractal->setGeometry(QRect(100, 170, 200, 24));
            m_btnSpiralFractal = new QPushButton(this);
            m_btnSpiralFractal->setGeometry(QRect(100, 210, 200, 24));
            m_btnClose = new QPushButton(this);
            m_btnClose->setGeometry(QRect(100, 350, 200, 24));
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
            connect(m_btnMyFractal, SIGNAL(clicked()), SLOT(slotBtnOpenMyFractal()));
            connect(m_btnMapleFractal, SIGNAL(clicked()), SLOT(slotBtnOpenMapleFractal()));
            connect(m_btnSpiralFractal, SIGNAL(clicked()), SLOT(slotBtnOpenSpiralFractal()));
            connect(m_btnClose, SIGNAL(clicked()), SLOT(close()));
        }

        ~MainMenu() = default;

    private:
        void setText() {
            this->setWindowTitle(QString::fromUtf8("Fractal Generator"));
            m_btnSheetFractal->setText(QString::fromUtf8("Лист папоротника"));
            m_btnFirFractal->setText(QString::fromUtf8("Елка"));
            m_btnMyFractal->setText(QString::fromUtf8("Шоу \"эксперименты\""));
            m_btnClose->setText(QString::fromUtf8("Закрыть программу"));
            m_Title->setText(QString::fromUtf8("Fractal Generator"));
            m_btnMapleFractal->setText(QString::fromUtf8("Кленовый лист"));
            m_btnSpiralFractal->setText(QString::fromUtf8("Спираль"));
        }

    private slots :

        void slotBtnOpenSheetFractal() {
            m_sheetFractal = std::make_unique<SheetFractal>("Лист папоротника");
            m_sheetFractal->show();
        }

        void slotBtnOpenFirFractal(){
            m_firFractal = std::make_unique<FirFractal>("Ёлочка");
            m_firFractal->show();
        }

        void slotBtnOpenMyFractal(){
            m_myFractal = std::make_unique<MyFractal>("Шоу \"Эксперименты\"");
            m_myFractal->show();
        }

        void slotBtnOpenMapleFractal(){
            m_mapleFractal = std::make_unique<MapleFractal>("Кленовый лист");
            m_mapleFractal->show();
        }

        void slotBtnOpenSpiralFractal(){
            m_spiralFractal = std::make_unique<SpiralFractal>("Спираль");
            m_spiralFractal->show();
        }
    };
}