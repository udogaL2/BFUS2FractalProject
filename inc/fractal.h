#pragma once

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

        void setAdditionalLaws(const math::Vec2d &fa1, const math::Vec2d &fa2, const math::Vec2d &fa3,
                               const math::Vec2d &fa4);

        void setProbability(double p1, double p2, double p3);

        void setBackgroundColor(images::Pixel &pixel);

        void setMainColor(images::Pixel &pixel);

        void setFractalColor();

        void setRandomColor();

        void setPathToSave(std::string &path);

        void setImageSize(int size);

        void setFractalHeight(int i_x, int i_y);

        void setD_x(int d_x);

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
        math::Vec2d m_thirdAdditionalLaw;
        math::Vec2d m_fourthAdditionalLaw;

        int m_imageHeight{}, m_imageWidth{};
        int m_fractalHeight{}, m_fractalWidth{};
        int md_x{};

        double m_probability1{}, m_probability2{}, m_probability3{};

        std::unique_ptr<images::BMP> m_bmp;

        std::string m_pathToSave;

        static images::Pixel getFractalPixel(int x, int y, std::vector<int> &nums);
    };
}