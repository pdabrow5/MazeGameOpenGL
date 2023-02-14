#include "shader.hpp"

class BasicShader final : public Shader {
  const char* GetVertexCode() const override;
  const char* GetFragmentCode() const override;
};