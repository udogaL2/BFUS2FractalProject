#pragma once

#include "FractalWindow.h"

namespace fg {
    class SpiralFractal : public FractalGenerator {
        Q_OBJECT
    public:

        explicit SpiralFractal(const QString &fractalName, QWidget *pwgt = nullptr) : FractalGenerator(fractalName) {
            QFont font;
            font.setPointSize(12);

            m_imageWindow = new QLabel(this);
            m_imageWindow->setGeometry(QRect(330, 70, 450, 450));

            m_btnShowImage = new QPushButton(this);
            m_btnShowImage->setText(QString::fromUtf8("отобразить"));
            m_btnShowImage->setGeometry(QRect(90, 530, 141, 31));
            m_btnShowImage->setFont(font);

            line_6 = new QFrame(this);
            line_6->setGeometry(QRect(330, 70, 450, 3));
            line_6->setFrameShape(QFrame::HLine);
            line_6->setFrameShadow(QFrame::Sunken);

            line_7 = new QFrame(this);
            line_7->setGeometry(QRect(330, 70, 3, 450));
            line_7->setFrameShape(QFrame::VLine);
            line_7->setFrameShadow(QFrame::Sunken);

            line_8 = new QFrame(this);
            line_8->setGeometry(QRect(330, 520, 450, 3));
            line_8->setFrameShape(QFrame::HLine);
            line_8->setFrameShadow(QFrame::Sunken);

            line_9 = new QFrame(this);
            line_9->setGeometry(QRect(780, 70, 3, 450));
            line_9->setFrameShape(QFrame::VLine);
            line_9->setFrameShadow(QFrame::Sunken);

            connect(m_btnGenerate, SIGNAL(clicked()), SLOT(slotBtnGenerate()));
            connect(m_btnShowImage, SIGNAL(clicked()), SLOT(slotBtnShowImage()));
        }

        ~SpiralFractal() override = default;

    private:
        QLabel *m_imageWindow;

        QPushButton *m_btnShowImage;

        QFrame *line_6;
        QFrame *line_7;
        QFrame *line_8;
        QFrame *line_9;

    private slots:
        void slotBtnGenerate() override{
            // Подробные комментарии для этой функции указаны в MapleFractal.h

            int d_x = m_hSlider_dx->value();
            int d_y = m_hSlider_dy->value();

            int size = stoi(m_comboBox->currentText().toStdString());

            saveAsMsg();

            if (m_PathToSave.isEmpty()) {
                errorSaveMsg();
                return;
            }

            math::Mat22d f1({{{-0.87, 0.23},
                              {-0.23, -0.87}}});
            math::Mat22d f2({{{-0.34, 0.21},
                              {-0.21, -0.34}}});
            math::Mat22d f3({{{0, 0},
                              {0, 0}}});

            math::Vec2d fp1({{{0}, {0}}});
            math::Vec2d fp2({{{1.34}, {0.21}}});

            images::Fractal fr;

            // т.к. в генерации данного фрактала участвует всего два закона, то две из трех вероятностей отрицательны
            fr.setProbability(0.5, -1, -1);
            fr.setD_x(size / 2);

            fr.setMainLaws(f1, f2, f3, f3);
            fr.setAdditionalLaws(fp1, fp2, fp1, fp1);

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
                    QString::fromUtf8("Фрактал был успешно сгенерирован!\nДля отображения на экране нажмите \"Отобразить\"."));
            msgBox.exec();
        }

        void slotBtnShowImage(){
            if (m_PathToSave.isEmpty()) {
                errorSaveMsg();
                return;
            }

            QImage fractalImage;
            fractalImage.load(m_PathToSave);

            if (fractalImage.isNull()) {
                m_imageWindow->setText("Error while loading!");
                return;
            }

            m_imageWindow->setText("");
            auto fractalPixmap = QPixmap::fromImage(fractalImage);
            fractalPixmap = fractalPixmap.scaled(450, 450, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
            m_imageWindow->setPixmap(fractalPixmap);
        }
    };

}