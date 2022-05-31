#pragma once

#include "FractalWindow.h"
#include "BMP.h"

using math::Mat22d;
using math::Vec2d;

namespace fg {
    class MyFractal : public FractalGenerator {
    Q_OBJECT
    public:

        explicit MyFractal(const QString &fractalName, QWidget *pwgt = nullptr) : FractalGenerator(fractalName) {
            QFont font;
            font.setPointSize(12);
            label = new QLabel(this);
            label->setGeometry(QRect(380, 60, 81, 21));
            label->setFont(font);
            label->setText(QString::fromUtf8("Закон 1"));

            label_2 = new QLabel(this);
            label_2->setGeometry(QRect(380, 170, 81, 21));
            label_2->setFont(font);
            label_2->setText(QString::fromUtf8("Закон 2"));

            label_3 = new QLabel(this);
            label_3->setGeometry(QRect(380, 280, 81, 21));
            label_3->setFont(font);
            label_3->setText(QString::fromUtf8("Закон 3"));

            label_4 = new QLabel(this);
            label_4->setGeometry(QRect(380, 390, 81, 21));
            label_4->setFont(font);
            label_4->setText(QString::fromUtf8("Закон 4"));

            m_SpinBoxFirst = new QDoubleSpinBox(this);
            m_SpinBoxFirst->setGeometry(QRect(440, 90, 62, 22));
            m_SpinBoxFirst->setMinimum(-1.0);
            m_SpinBoxFirst->setMaximum(1.0);
            m_SpinBoxFirst->setSingleStep(0.01);
            m_SpinBoxFirst->setValue(0);

            m_SpinBoxFirst_2 = new QDoubleSpinBox(this);
            m_SpinBoxFirst_2->setGeometry(QRect(570, 90, 62, 22));
            m_SpinBoxFirst_2->setMinimum(-1.0);
            m_SpinBoxFirst_2->setMaximum(1.0);
            m_SpinBoxFirst_2->setSingleStep(0.01);
            m_SpinBoxFirst_2->setValue(0);

            m_SpinBoxFirst_3 = new QDoubleSpinBox(this);
            m_SpinBoxFirst_3->setGeometry(QRect(440, 130, 62, 22));
            m_SpinBoxFirst_3->setMinimum(-1.0);
            m_SpinBoxFirst_3->setMaximum(1.0);
            m_SpinBoxFirst_3->setSingleStep(0.01);
            m_SpinBoxFirst_3->setValue(0);

            m_SpinBoxFirst_4 = new QDoubleSpinBox(this);
            m_SpinBoxFirst_4->setGeometry(QRect(570, 130, 62, 22));
            m_SpinBoxFirst_4->setMinimum(-1.0);
            m_SpinBoxFirst_4->setMaximum(1.0);
            m_SpinBoxFirst_4->setSingleStep(0.01);
            m_SpinBoxFirst_4->setValue(0.16);


            m_SpinBoxSecond_5 = new QDoubleSpinBox(this);
            m_SpinBoxSecond_5->setGeometry(QRect(440, 200, 62, 22));
            m_SpinBoxSecond_5->setMinimum(-1.0);
            m_SpinBoxSecond_5->setMaximum(1.0);
            m_SpinBoxSecond_5->setSingleStep(0.01);
            m_SpinBoxSecond_5->setValue(0.85);

            m_SpinBoxSecond_6 = new QDoubleSpinBox(this);
            m_SpinBoxSecond_6->setGeometry(QRect(570, 200, 62, 22));
            m_SpinBoxSecond_6->setMinimum(-1.0);
            m_SpinBoxSecond_6->setMaximum(1.0);
            m_SpinBoxSecond_6->setSingleStep(0.01);
            m_SpinBoxSecond_6->setValue(0.04);

            m_SpinBoxSecond_7 = new QDoubleSpinBox(this);
            m_SpinBoxSecond_7->setGeometry(QRect(440, 240, 62, 22));
            m_SpinBoxSecond_7->setMinimum(-1.0);
            m_SpinBoxSecond_7->setMaximum(1.0);
            m_SpinBoxSecond_7->setSingleStep(0.01);
            m_SpinBoxSecond_7->setValue(-0.04);

            m_SpinBoxSecond_8 = new QDoubleSpinBox(this);
            m_SpinBoxSecond_8->setGeometry(QRect(570, 240, 62, 22));
            m_SpinBoxSecond_8->setMinimum(-1.0);
            m_SpinBoxSecond_8->setMaximum(1.0);
            m_SpinBoxSecond_8->setSingleStep(0.01);
            m_SpinBoxSecond_8->setValue(0.85);

            m_SpinBoxThird_9 = new QDoubleSpinBox(this);
            m_SpinBoxThird_9->setGeometry(QRect(440, 310, 62, 22));
            m_SpinBoxThird_9->setMinimum(-1.0);
            m_SpinBoxThird_9->setMaximum(1.0);
            m_SpinBoxThird_9->setSingleStep(0.01);
            m_SpinBoxThird_9->setValue(0.2);

            m_SpinBoxThird_10 = new QDoubleSpinBox(this);
            m_SpinBoxThird_10->setGeometry(QRect(570, 310, 62, 22));
            m_SpinBoxThird_10->setMinimum(-1.0);
            m_SpinBoxThird_10->setMaximum(1.0);
            m_SpinBoxThird_10->setSingleStep(0.01);
            m_SpinBoxThird_10->setValue(-0.26);

            m_SpinBoxThird_11 = new QDoubleSpinBox(this);
            m_SpinBoxThird_11->setGeometry(QRect(440, 350, 62, 22));
            m_SpinBoxThird_11->setMinimum(-1.0);
            m_SpinBoxThird_11->setMaximum(1.0);
            m_SpinBoxThird_11->setSingleStep(0.01);
            m_SpinBoxThird_11->setValue(0.23);

            m_SpinBoxThird_12 = new QDoubleSpinBox(this);
            m_SpinBoxThird_12->setGeometry(QRect(570, 350, 62, 22));
            m_SpinBoxThird_12->setMinimum(-1.0);
            m_SpinBoxThird_12->setMaximum(1.0);
            m_SpinBoxThird_12->setSingleStep(0.01);
            m_SpinBoxThird_12->setValue(0.22);

            m_SpinBoxFourth_13 = new QDoubleSpinBox(this);
            m_SpinBoxFourth_13->setGeometry(QRect(440, 420, 62, 22));
            m_SpinBoxFourth_13->setMinimum(-1.0);
            m_SpinBoxFourth_13->setMaximum(1.0);
            m_SpinBoxFourth_13->setSingleStep(0.01);
            m_SpinBoxFourth_13->setValue(-0.15);

            m_SpinBoxFourth_14 = new QDoubleSpinBox(this);
            m_SpinBoxFourth_14->setGeometry(QRect(570, 420, 62, 22));
            m_SpinBoxFourth_14->setMinimum(-1.0);
            m_SpinBoxFourth_14->setMaximum(1.0);
            m_SpinBoxFourth_14->setSingleStep(0.01);
            m_SpinBoxFourth_14->setValue(0.28);

            m_SpinBoxFourth_15 = new QDoubleSpinBox(this);
            m_SpinBoxFourth_15->setGeometry(QRect(440, 460, 62, 22));
            m_SpinBoxFourth_15->setMinimum(-1.0);
            m_SpinBoxFourth_15->setMaximum(1.0);
            m_SpinBoxFourth_15->setSingleStep(0.01);
            m_SpinBoxFourth_15->setValue(0.26);

            m_SpinBoxFourth_16 = new QDoubleSpinBox(this);
            m_SpinBoxFourth_16->setGeometry(QRect(570, 460, 62, 22));
            m_SpinBoxFourth_16->setMinimum(-1.0);
            m_SpinBoxFourth_16->setMaximum(1.0);
            m_SpinBoxFourth_16->setSingleStep(0.01);
            m_SpinBoxFourth_16->setValue(0.24);

            label_5 = new QLabel(this);
            label_5->setGeometry(QRect(380, 490, 101, 21));
            label_5->setFont(font);
            label_5->setText(QString::fromUtf8("Доп. законы"));

            m_SpinBoxAddFirst_1 = new QDoubleSpinBox(this);
            m_SpinBoxAddFirst_1->setGeometry(QRect(440, 520, 62, 22));
            m_SpinBoxAddFirst_1->setMinimum(-2.0);
            m_SpinBoxAddFirst_1->setMaximum(2.0);
            m_SpinBoxAddFirst_1->setSingleStep(0.01);
            m_SpinBoxAddFirst_1->setValue(0);

            m_SpinBoxAddFirst_2 = new QDoubleSpinBox(this);
            m_SpinBoxAddFirst_2->setGeometry(QRect(570, 520, 62, 22));
            m_SpinBoxAddFirst_2->setMinimum(-2.0);
            m_SpinBoxAddFirst_2->setMaximum(2.0);
            m_SpinBoxAddFirst_2->setSingleStep(0.01);
            m_SpinBoxAddFirst_2->setValue(1.6);

            m_SpinBoxAddSecond_1 = new QDoubleSpinBox(this);
            m_SpinBoxAddSecond_1->setGeometry(QRect(440, 560, 62, 22));
            m_SpinBoxAddSecond_1->setMinimum(-2.0);
            m_SpinBoxAddSecond_1->setMaximum(2.0);
            m_SpinBoxAddSecond_1->setSingleStep(0.01);
            m_SpinBoxAddSecond_1->setValue(0);

            m_SpinBoxAddSecond_2 = new QDoubleSpinBox(this);
            m_SpinBoxAddSecond_2->setGeometry(QRect(570, 560, 62, 22));
            m_SpinBoxAddSecond_2->setMinimum(-2.0);
            m_SpinBoxAddSecond_2->setMaximum(2.0);
            m_SpinBoxAddSecond_2->setSingleStep(0.01);
            m_SpinBoxAddSecond_2->setValue(0.44);

            line = new QFrame(this);
            line->setGeometry(QRect(440, 540, 191, 21));
            line->setFrameShape(QFrame::HLine);
            line->setFrameShadow(QFrame::Sunken);

            connect(m_btnGenerate, SIGNAL(clicked()), SLOT(slotBtnGenerate()));
        }

        ~MyFractal() override = default;

    private:
        QLabel *label;
        QLabel *label_2;
        QLabel *label_3;
        QLabel *label_4;
        QLabel *label_5;

        QFrame *line;

        QDoubleSpinBox *m_SpinBoxFirst;
        QDoubleSpinBox *m_SpinBoxFirst_2;
        QDoubleSpinBox *m_SpinBoxFirst_3;
        QDoubleSpinBox *m_SpinBoxFirst_4;
        QDoubleSpinBox *m_SpinBoxSecond_5;
        QDoubleSpinBox *m_SpinBoxSecond_6;
        QDoubleSpinBox *m_SpinBoxSecond_7;
        QDoubleSpinBox *m_SpinBoxSecond_8;
        QDoubleSpinBox *m_SpinBoxThird_9;
        QDoubleSpinBox *m_SpinBoxThird_10;
        QDoubleSpinBox *m_SpinBoxThird_11;
        QDoubleSpinBox *m_SpinBoxThird_12;
        QDoubleSpinBox *m_SpinBoxFourth_13;
        QDoubleSpinBox *m_SpinBoxFourth_14;
        QDoubleSpinBox *m_SpinBoxFourth_15;
        QDoubleSpinBox *m_SpinBoxFourth_16;

        QDoubleSpinBox *m_SpinBoxAddFirst_1;
        QDoubleSpinBox *m_SpinBoxAddFirst_2;
        QDoubleSpinBox *m_SpinBoxAddSecond_1;
        QDoubleSpinBox *m_SpinBoxAddSecond_2;


    private slots:
        void slotBtnGenerate() override{
            int d_x = m_hSlider_dx->value();
            int d_y = m_hSlider_dy->value();

            int size = stoi(m_comboBox->currentText().toStdString());

            saveAsMsg();

            if (m_PathToSave.isEmpty()) {
                errorSaveMsg();
                return;
            }

            math::Mat22d f1({{{m_SpinBoxFirst->value(), m_SpinBoxFirst_2->value()},
                              {m_SpinBoxFirst_3->value(), m_SpinBoxFirst_4->value()}}});
            math::Mat22d f2({{{m_SpinBoxSecond_5->value(), m_SpinBoxSecond_6->value()},
                              {m_SpinBoxSecond_7->value(), m_SpinBoxSecond_8->value()}}});
            math::Mat22d f3({{{m_SpinBoxThird_9->value(), m_SpinBoxThird_10->value()},
                              {m_SpinBoxThird_11->value(), m_SpinBoxThird_12->value()}}});
            math::Mat22d f4({{{m_SpinBoxFourth_13->value(), m_SpinBoxFourth_14->value()},
                              {m_SpinBoxFourth_15->value(), m_SpinBoxFourth_16->value()}}});

            math::Vec2d fp1({{{m_SpinBoxAddFirst_1->value()}, {m_SpinBoxAddFirst_2->value()}}});
            math::Vec2d fp2({{{m_SpinBoxAddSecond_1->value()}, {m_SpinBoxAddSecond_2->value()}}});
            math::Vec2d fp3({{{0}, {0}}});

            images::Fractal fr;

            fr.setMainLaws(f1, f2, f3, f4);
            fr.setAdditionalLaws(fp3, fp1, fp1, fp2);

            fr.setImageSize(size);
            fr.setFractalHeight(d_x, d_y);

            std::string path = m_PathToSave.toStdString();
            fr.setPathToSave(path);

            images::Pixel bg_px{static_cast<uint8_t>(m_BGColor.blue()), static_cast<uint8_t>(m_BGColor.green()),
                                static_cast<uint8_t>(m_BGColor.red())};
            fr.setBackgroundColor(bg_px);

            if (radioButton->isChecked()) {
                images::Pixel main_px{static_cast<uint8_t>(m_mainColor.blue()), static_cast<uint8_t>(m_mainColor.green()),
                                      static_cast<uint8_t>(m_mainColor.red())};
                fr.setMainColor(main_px);
            } else if (radioButton_2->isChecked()) {
                fr.setFractalColor();
            } else if (radioButton_3->isChecked()) {
                fr.setRandomColor();
            }

            fr.generate();
            fr.save();

            QMessageBox msgBox;
            msgBox.setWindowTitle(QString::fromUtf8("Успех"));
            msgBox.setText(
                    QString::fromUtf8("Фрактал был успешно сгенерирован!"));
            msgBox.exec();
        }
    };
}