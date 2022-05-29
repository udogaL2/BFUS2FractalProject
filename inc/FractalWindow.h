#pragma once

#include <QPushButton>
#include <QFileDialog>
#include <QLabel>
#include <QLineEdit>
#include <QSlider>
#include <QComboBox>
#include <QRadioButton>
#include <QObject>
#include <QSpinBox>
#include <QColorDialog>
#include <QMessageBox>
#include <QErrorMessage>

#include "fractal.h"

namespace fg {
    class FractalGenerator : public QWidget {
    Q_OBJECT
    private:
        QLabel *m_imageWindow;
        QLabel *m_fractalTitleLabel;

        QSlider *m_hSlider_dx;
        QSlider *m_hSlider_dy;

        QLineEdit *m_hSliderTitle_dx;
        QLineEdit *m_hSliderTitle_dy;
        QLineEdit *m_BGColorTitle;
        QLineEdit *m_mainColorTitle;
        QLineEdit *m_imgResolutionTitle;

        QWidget *m_BGColorWidget;
        QWidget *m_mainColorWidget;
        QComboBox *m_comboBox;

        QPushButton *m_btnBGColor;
        QPushButton *m_btnMainColor;
        QPushButton *m_btnGenerate;
        QPushButton *m_btnShowImage;
        QPushButton *m_btnClose;

        QRadioButton *radioButton;
        QRadioButton *radioButton_2;
        QRadioButton *radioButton_3;

        QFrame *line;
        QFrame *line_2;
        QFrame *line_3;
        QFrame *line_4;
        QFrame *line_5;
        QFrame *line_6;
        QFrame *line_7;
        QFrame *line_8;
        QFrame *line_9;

        QSpinBox *m_spinBox_dx;
        QSpinBox *m_spinBox_dy;

        QColor m_mainColor;
        QColor m_BGColor;
        QString m_PathToSave = nullptr;

    public:
        explicit FractalGenerator(const QString &fractalName, QWidget *pwgt = nullptr) : QWidget(pwgt) {
            this->resize(800, 600);
            this->setMinimumSize(QSize(800, 600));
            this->setMaximumSize(QSize(800, 600));

            m_BGColor.setRgb(255, 255, 255);
            m_mainColor.setRgb(0, 0, 0);

            // QFont
            QFont font;
            font.setPointSize(12);
            QFont font1;
            font1.setPointSize(15);
            QFont font3;
            font3.setPointSize(10);
            // *QFont

            // QLabel
            m_imageWindow = new QLabel(this);
            m_imageWindow->setGeometry(QRect(330, 70, 450, 450));

            m_fractalTitleLabel = new QLabel(this);
            m_fractalTitleLabel->setGeometry(QRect(20, 10, 271, 31));
            m_fractalTitleLabel->setFont(font1);
            m_fractalTitleLabel->setAlignment(Qt::AlignCenter);
            // *QLabel


            // QSlider
            m_hSlider_dx = new QSlider(this);
            m_hSlider_dx->setGeometry(QRect(20, 100, 251, 22));
            m_hSlider_dx->setMinimum(1);
            m_hSlider_dx->setMaximum(20);
            m_hSlider_dx->setValue(12);
            m_hSlider_dx->setOrientation(Qt::Horizontal);

            m_hSlider_dy = new QSlider(this);
            m_hSlider_dy->setGeometry(QRect(20, 170, 251, 22));
            m_hSlider_dy->setMinimum(1);
            m_hSlider_dy->setMaximum(10);
            m_hSlider_dy->setValue(10);
            m_hSlider_dy->setOrientation(Qt::Horizontal);
            // *QSlider

            // QLineEdit
            m_hSliderTitle_dx = new QLineEdit(this);
            m_hSliderTitle_dx->setGeometry(QRect(10, 60, 291, 31));
            m_hSliderTitle_dx->setFont(font);
            m_hSliderTitle_dx->setFrame(true);
            m_hSliderTitle_dx->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
            m_hSliderTitle_dx->setReadOnly(true);

            m_hSliderTitle_dy = new QLineEdit(this);
            m_hSliderTitle_dy->setGeometry(QRect(10, 130, 291, 31));
            m_hSliderTitle_dy->setFont(font);
            m_hSliderTitle_dy->setFrame(true);
            m_hSliderTitle_dy->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
            m_hSliderTitle_dy->setReadOnly(true);

            m_BGColorTitle = new QLineEdit(this);
            m_BGColorTitle->setGeometry(QRect(10, 230, 171, 22));
            m_BGColorTitle->setFont(font);
            m_BGColorTitle->setAlignment(Qt::AlignCenter);
            m_BGColorTitle->setReadOnly(true);

            m_mainColorTitle = new QLineEdit(this);
            m_mainColorTitle->setGeometry(QRect(10, 260, 171, 22));
            m_mainColorTitle->setFont(font);
            m_mainColorTitle->setAlignment(Qt::AlignCenter);
            m_mainColorTitle->setReadOnly(true);

            m_imgResolutionTitle = new QLineEdit(this);
            m_imgResolutionTitle->setGeometry(QRect(10, 370, 291, 31));
            m_imgResolutionTitle->setFont(font);
            m_imgResolutionTitle->setFrame(true);
            m_imgResolutionTitle->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
            m_imgResolutionTitle->setReadOnly(true);
            // *QLineEdit

            // QWidget
            m_BGColorWidget = new QWidget(this);
            m_BGColorWidget->setGeometry(QRect(190, 230, 61, 21));
            m_BGColorWidget->setAutoFillBackground(true);

            m_mainColorWidget = new QWidget(this);
            m_mainColorWidget->setGeometry(QRect(190, 260, 61, 21));
            m_mainColorWidget->setAutoFillBackground(true);
            // *QWidget

            // QComboBox
            m_comboBox = new QComboBox(this);
            m_comboBox->addItem(QString::fromUtf8(("1000px")));
            m_comboBox->addItem(QString::fromUtf8(("1500px")));
            m_comboBox->addItem(QString::fromUtf8(("2000px")));
            m_comboBox->setGeometry(QRect(10, 410, 291, 22));
            // *QComboBox

            // QPushButton
            m_btnBGColor = new QPushButton(this);
            m_btnBGColor->setGeometry(QRect(260, 230, 41, 24));

            m_btnMainColor = new QPushButton(this);
            m_btnMainColor->setGeometry(QRect(260, 260, 41, 24));

            m_btnGenerate = new QPushButton(this);
            m_btnGenerate->setGeometry(QRect(90, 490, 141, 31));
            m_btnGenerate->setFont(font);

            m_btnShowImage = new QPushButton(this);
            m_btnShowImage->setGeometry(QRect(90, 530, 141, 31));
            m_btnShowImage->setFont(font);

            m_btnClose = new QPushButton(this);
            m_btnClose->setGeometry(QRect(710, 10, 75, 24));
            m_btnClose->setFont(font3);
            // *QPushButton

            // QRadioButton
            radioButton = new QRadioButton(this);
            radioButton->setGeometry(QRect(20, 290, 89, 20));
            radioButton->setFont(font);
            radioButton->setChecked(true);

            radioButton_2 = new QRadioButton(this);
            radioButton_2->setGeometry(QRect(20, 320, 161, 20));
            radioButton_2->setFont(font);

            radioButton_3 = new QRadioButton(this);
            radioButton_3->setGeometry(QRect(150, 320, 141, 20));
            radioButton_3->setFont(font);
            // *QRadioButton

            // QFrame
            line = new QFrame(this);
            line->setGeometry(QRect(309, -40, 21, 691));
            line->setFrameShape(QFrame::VLine);
            line->setFrameShadow(QFrame::Sunken);

            line_2 = new QFrame(this);
            line_2->setGeometry(QRect(0, 440, 318, 16));
            line_2->setFrameShape(QFrame::HLine);
            line_2->setFrameShadow(QFrame::Sunken);

            line_3 = new QFrame(this);
            line_3->setGeometry(QRect(0, 350, 318, 16));
            line_3->setFrameShape(QFrame::HLine);
            line_3->setFrameShadow(QFrame::Sunken);

            line_4 = new QFrame(this);
            line_4->setGeometry(QRect(0, 200, 318, 16));
            line_4->setFrameShape(QFrame::HLine);
            line_4->setFrameShadow(QFrame::Sunken);

            line_5 = new QFrame(this);
            line_5->setGeometry(QRect(0, 40, 318, 16));
            line_5->setFrameShape(QFrame::HLine);
            line_5->setFrameShadow(QFrame::Sunken);


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
            // *QFrame

            // QSpinBox
            m_spinBox_dx = new QSpinBox(this);
            m_spinBox_dx->setGeometry(QRect(280, 100, 31, 22));
            m_spinBox_dx->setAlignment(Qt::AlignCenter);
            m_spinBox_dx->setReadOnly(true);
            m_spinBox_dx->setButtonSymbols(QAbstractSpinBox::NoButtons);
            m_spinBox_dx->setMinimum(1);
            m_spinBox_dx->setMaximum(20);
            m_spinBox_dx->setValue(12);

            m_spinBox_dy = new QSpinBox(this);
            m_spinBox_dy->setGeometry(QRect(280, 170, 31, 22));
            m_spinBox_dy->setAlignment(Qt::AlignCenter);
            m_spinBox_dy->setReadOnly(true);
            m_spinBox_dy->setButtonSymbols(QAbstractSpinBox::NoButtons);
            m_spinBox_dy->setMinimum(1);
            m_spinBox_dy->setMaximum(10);
            m_spinBox_dy->setValue(10);
            // *QSpinBox

            // Синхронизация значений
            connect(m_hSlider_dx, &QSlider::valueChanged, m_spinBox_dx, &QSpinBox::setValue);
            connect(m_hSlider_dy, &QSlider::valueChanged, m_spinBox_dy, &QSpinBox::setValue);

            // Отображение текста у элементов
            this->setText(fractalName);

            // Значение цветов по умолчанию
            QPalette palette = m_BGColorWidget->palette();
            palette.setColor(QPalette::Window, m_BGColor);
            m_BGColorWidget->setPalette(palette);
            palette = m_mainColorWidget->palette();
            palette.setColor(QPalette::Window, m_mainColor);
            m_mainColorWidget->setPalette(palette);

            // Подключение кнопок
            connect(m_btnBGColor, SIGNAL(clicked()), SLOT(slotBtnBGColorDialog()));
            connect(m_btnMainColor, SIGNAL(clicked()), SLOT(slotBtnMainColorDialog()));
            connect(m_btnGenerate, SIGNAL(clicked()), SLOT(slotBtnGenerate()));
            connect(m_btnShowImage, SIGNAL(clicked()), SLOT(slotBtnShowImage()));
            connect(m_btnClose, SIGNAL(clicked()), SLOT(close()));
        }

        ~FractalGenerator() override = default;

    private:
        void setText(const QString &name) {
            this->setWindowTitle(QString::fromUtf8("Fractal Generator"));
            m_fractalTitleLabel->setText(name);
            m_hSliderTitle_dx->setText(QString::fromUtf8("Размер по оси x"));
            m_hSliderTitle_dy->setText(QString::fromUtf8("Размер по оси y"));
            m_BGColorTitle->setText(QString::fromUtf8("Цвет фона"));
            m_mainColorTitle->setText(QString::fromUtf8("Основной цвет"));
            m_imgResolutionTitle->setText(QString::fromUtf8("Разрешение"));
            radioButton->setText(QString::fromUtf8("основной"));
            radioButton_2->setText(QString::fromUtf8("фрактальный"));
            radioButton_3->setText(QString::fromUtf8("случайный"));
            m_btnGenerate->setText(QString::fromUtf8("сгенерировать"));
            m_btnShowImage->setText(QString::fromUtf8("отобразить"));
            m_btnClose->setText(QString::fromUtf8("закрыть"));
        }

        void saveAsMsg() {
            // Диалоговое окно для получения пути для сохранения файла
            QString strFilter;
            m_PathToSave = QFileDialog::getSaveFileName(
                    nullptr,  // нулевой указатель на объект предка
                    tr("Путь для сохранения изображения"),  // надпись самого окна
                    "Fractal",  // имя для файла
                    "*.bmp",  // строка с тремя графическими форматами, разделенными между собой двумя символами точки с запятой: ;; - чтобы каждый из них был представлен отдельным элементом
                    &strFilter  // место, куда будет помещен выбранный пользователем формат
            );
        }

        void errorSaveMsg() {
            // Диалоговое окно для сообщения об ошибке
            QErrorMessage errorMessage;
            errorMessage.setWindowTitle(QString::fromUtf8("Ошибка"));
            errorMessage.showMessage(
                    QString::fromUtf8("Произошла ошибка, путь файла не указан. Повторите попытку."));
            errorMessage.exec();
        }

    private slots:

        void slotBtnBGColorDialog() {
            // Диалоговое окно для получения цвета фона
            auto FrontColor = QColorDialog::getColor(Qt::white, this, QString::fromUtf8("Выберите цвет фона"),
                                                     QColorDialog::DontUseNativeDialog);
            m_BGColor.setRgb(FrontColor.rgb());
            if (m_BGColor.isValid()) {
                QPalette palette = m_BGColorWidget->palette();
                palette.setColor(QPalette::Window, m_BGColor);
                m_BGColorWidget->setPalette(palette);
            }
        };

        void slotBtnMainColorDialog() {
            // Диалоговое окно для получения основного цвета
            auto FrontColor = QColorDialog::getColor(Qt::white, this, QString::fromUtf8("Выберите основной цвет"),
                                                     QColorDialog::DontUseNativeDialog);
            m_mainColor.setRgb(FrontColor.rgb());
            if (m_mainColor.isValid()) {
                QPalette palette = m_mainColorWidget->palette();
                palette.setColor(QPalette::Window, m_mainColor);
                m_mainColorWidget->setPalette(palette);
            }
        };

        void slotBtnGenerate() {
            int d_x = m_hSlider_dx->value();
            int d_y = m_hSlider_dy->value();

            int size = stoi(m_comboBox->currentText().toStdString());

            saveAsMsg();

            if (m_PathToSave.isEmpty()) {
                errorSaveMsg();
                return;
            }

            images::Pixel bg_px{static_cast<uint8_t>(m_BGColor.blue()), static_cast<uint8_t>(m_BGColor.green()),
                                static_cast<uint8_t>(m_BGColor.red())};
            images::Pixel main_px{static_cast<uint8_t>(m_mainColor.blue()), static_cast<uint8_t>(m_mainColor.green()),
                                  static_cast<uint8_t>(m_mainColor.red())};

            images::Fractal fr;
            fr.setImageSize(size);
            fr.setFractalHeight(d_x, d_y);

            std::string path = m_PathToSave.toStdString();
            fr.setPathToSave(path);

            if (radioButton->isChecked()) {
                fr.setBackgroundColor(bg_px);
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
                    QString::fromUtf8("Фрактал был успешно сгенерирован!\nДля отображения нажмите 'Отобразить'."));
            msgBox.exec();
        }

        void slotBtnShowImage() {
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
            fractalPixmap = fractalPixmap.scaled(450, 450, Qt::IgnoreAspectRatio, Qt::FastTransformation);
            m_imageWindow->setPixmap(fractalPixmap);
        }
    };

}