#include "../inc/fractal.h"

namespace images {
    Fractal::Fractal() {
        m_backgroundColor = images::Pixel({255, 255, 255});
        m_mainColor = images::Pixel({0, 0, 0});

        m_firstMainLaw = math::Mat22d({{{0, 0}, {0, 0.16}}});
        m_secondMainLaw = math::Mat22d({{{0.85, 0.04}, {-0.04, 0.85}}});
        m_thirdMainLaw = math::Mat22d({{{0.2, -0.26}, {0.23, 0.2}}});
        m_fourthMainLaw = math::Mat22d({{{-0.15, 0.28}, {0.26, 0.24}}});

        m_firstAdditionalLaw = math::Vec2d({{{0}, {1.6}}});
        m_secondAdditionalLaw = math::Vec2d({{{0}, {0.44}}});
        m_thirdAdditionalLaw = math::Vec2d({{{0}, {1.6}}});
        m_fourthAdditionalLaw = math::Vec2d({{{0}, {0}}});

        m_imageHeight = m_imageWidth = 1000;

        m_fractalHeight = m_imageHeight / 10;
        m_fractalWidth = m_imageWidth / 12;

        md_x = 50;

        m_probability1 = 0.85;
        m_probability2 = 0.92;
        m_probability3 = 0.99;

        m_pathToSave = "../fractal.bmp";
    }

    Fractal::~Fractal() = default;

    void Fractal::setMainLaws(const math::Mat22d &f1, const math::Mat22d &f2, const math::Mat22d &f3,
                              const math::Mat22d &f4) {
        m_firstMainLaw = f1;
        m_secondMainLaw = f2;
        m_thirdMainLaw = f3;
        m_fourthMainLaw = f4;
    }

    void Fractal::setAdditionalLaws(const math::Vec2d &fa1, const math::Vec2d &fa2, const math::Vec2d &fa3,
                                    const math::Vec2d &fa4) {
        m_firstAdditionalLaw = fa1;
        m_secondAdditionalLaw = fa2;
        m_thirdAdditionalLaw = fa3;
        m_fourthAdditionalLaw = fa4;
    }

    void Fractal::setProbability(double p1, double p2, double p3){
        m_probability1 = p1;
        m_probability2 = p2;
        m_probability3 = p3;
    }

    void Fractal::setBackgroundColor(images::Pixel &pixel) {
        m_backgroundColor = pixel;
        m_isFractalColor = false;
        m_isRandomColor = false;
    }

    void Fractal::setMainColor(images::Pixel &pixel) {
        m_mainColor = pixel;
        m_isFractalColor = false;
        m_isRandomColor = false;
    }

    void Fractal::setFractalColor() {
        m_isRandomColor = false;
        m_isFractalColor = true;
    }

    void Fractal::setRandomColor() {
        m_isRandomColor = true;
        m_isFractalColor = false;
    }

    void Fractal::setPathToSave(std::string &path) {
        m_pathToSave = path;
    }

    void Fractal::setImageSize(int size) {
        m_imageHeight = size;
        m_imageWidth = size;
    }

    void Fractal::setFractalHeight(int i_x, int i_y) {
        m_fractalHeight = m_imageHeight / i_y;
        m_fractalWidth = m_imageWidth / i_x;
    }

    void Fractal::setD_x(int d_x){
        md_x = d_x;
    }

    void Fractal::generate() {
        double probability;
        int iterationCount = m_imageHeight * m_imageWidth *
                             (10 * float(m_isFractalColor or m_isRandomColor) +
                              0.5 * float(!(m_isFractalColor or m_isRandomColor)));

        m_bmp = std::make_unique<images::BMP>(m_imageWidth, m_imageHeight);
        m_bmp->Fill(m_backgroundColor);

        std::random_device rd;
        std::mt19937 int_gen(rd());
        std::uniform_int_distribution<> dist(1, 8);
        int_gen.seed(unsigned(std::time(nullptr)));

        std::mt19937 double_gen(rd());
        std::uniform_real_distribution<double> dist_probability(0, 1.0);
        double_gen.seed(unsigned(std::time(nullptr)));

        math::Vec2d current_cords({{{1.0}, {0.0}}});

        images::Pixel cur_pix = m_mainColor;
        std::vector<int> temp_nums;
        if (m_isRandomColor)
            temp_nums = {dist(int_gen), dist(int_gen), dist(int_gen)};
        if (m_isFractalColor)
            temp_nums = {1, 2, 6};
        while (iterationCount > 0) {
            probability = dist_probability(double_gen); // генерируем случайное число от 0 до 1 (вероятность)
            if (probability <= m_probability1) {
                current_cords = m_secondMainLaw * current_cords + m_firstAdditionalLaw;
            } else if (probability <= m_probability2) {
                current_cords = m_thirdMainLaw * current_cords + m_thirdAdditionalLaw;
            } else if (probability <= m_probability3) {
                current_cords = m_fourthMainLaw * current_cords + m_secondAdditionalLaw;
            } else {
                current_cords = m_firstMainLaw * current_cords + m_fourthAdditionalLaw;
            }
            int x = (int) (current_cords.get(0, 1) * m_fractalWidth + md_x);
            int y = (int) (current_cords.get(0, 0) * m_fractalHeight + m_imageHeight / 2);

            if (0 <= x and x < m_imageHeight and 0 <= y and y < m_imageWidth) {
                if (m_isFractalColor or m_isRandomColor) {
                    cur_pix = getFractalPixel(x, y, temp_nums);
                }
                m_bmp->Set(cur_pix, x, y);
            }
            iterationCount--;
        }
    }

    void Fractal::save() {
        m_bmp->Save(m_pathToSave);
    }

    void Fractal::save(std::string &path) {
        m_bmp->Save(path);
    }

    images::Pixel Fractal::getFractalPixel(int x, int y, std::vector<int> &nums) {
        uint8_t temp_mas[3];
        for (int i = 0; i < 3; i++) {
            int condition = nums[i];
            switch (condition) {
                case 1:
                    temp_mas[i] = static_cast<uint8_t>(255 - (y + x) % 255);
                    break;
                case 2:
                    temp_mas[i] = static_cast<uint8_t>(255 - (y - x) % 255);
                    break;
                case 3:
                    temp_mas[i] = static_cast<uint8_t>(255 - (x - y) % 255);
                    break;
                case 4:
                    temp_mas[i] = static_cast<uint8_t>(255 - (x * 2) % 255);
                    break;
                case 5:
                    temp_mas[i] = static_cast<uint8_t>(255 - (y * 2) % 255);
                    break;
                case 6:
                    temp_mas[i] = static_cast<uint8_t>(255 - (y * x) % 255);
                    break;
                case 7:
                    temp_mas[i] = static_cast<uint8_t>(255 - (x / y) % 255);
                    break;
                case 8:
                    temp_mas[i] = static_cast<uint8_t>(255 - (y / x) % 255);
                    break;
            }
        }
        return images::Pixel({temp_mas[0], temp_mas[1], temp_mas[2]});
    }
}

