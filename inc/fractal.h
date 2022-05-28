#include "BMP.h"
#include <string>
#include <random>
#include <memory>
#include <ctime>
#include <vector>

using math::Mat22d;
using math::Vec2d;

namespace images {
    class Fractal {
    public:
        Fractal();

        ~Fractal();

        void
        setMainLaws(const math::Mat22d &f1, const math::Mat22d &f2, const math::Mat22d &f3, const math::Mat22d &f4);

        void setAdditionalLaws(const math::Vec2d &fa1, const math::Vec2d &fa2);

        void setBackgroundColor(images::Pixel &pixel);

        void setMainColor(images::Pixel &pixel);

        void setRandomColor();

        void setPathToSave(std::string &path);

        void generate();

        void save();

        void save(std::string &path);

    private:
        images::Pixel m_backgroundColor{};
        images::Pixel m_mainColor{};

        bool m_isFractalColor = false;
        bool m_isRandomColor = false;

        math::Mat22d m_firstMainLaw;
        math::Mat22d m_secondMainLaw;
        math::Mat22d m_thirdMainLaw;
        math::Mat22d m_fourthMainLaw;

        math::Vec2d m_firstAdditionalLaw;
        math::Vec2d m_secondAdditionalLaw;

        int m_imageHeight{}, m_imageWidth{};
        int m_fractalHeight{}, m_fractalWidth{};

        std::unique_ptr<images::BMP> m_bmp;

        std::string m_pathToSave;

        static images::Pixel getFractalPixel(int x, int y, std::vector<int> &nums);
    };
}