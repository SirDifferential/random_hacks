#ifndef __SHADER_NORMALMAP_HPP_
#define __SHADER_NORMALMAP_HPP_

#include "shader.hpp"
#include "sprite.hpp"
#include <boost/shared_ptr.hpp>

class ShaderNormalMap : public Shader
{
private:
    int id;
    boost::shared_ptr<Sprite> colorMap;
    boost::shared_ptr<Sprite> normalMap;
public:
    ShaderNormalMap(const char* vs_filepath, const char* fs_filepath);
    ~ShaderNormalMap();
    void update();
    void action1();
    void action2();
    void action3();
    void action4();
    void action5();
    void action6();
    void action7();
    void action8();
};

#endif
