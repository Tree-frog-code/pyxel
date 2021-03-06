#ifndef PYXELCORE_GIF_WRITER_H_
#define PYXELCORE_GIF_WRITER_H_

#include "pyxelcore/common.h"

namespace pyxelcore {

class Image;

class GifWriter {
 public:
  static const int32_t TRANSPARENT_COLOR = COLOR_COUNT;

  GifWriter(const std::string& filename,
            int32_t width,
            int32_t height,
            const PaletteColor& palette_color,
            int32_t delay_time);
  ~GifWriter();

  void AddFrame(const Image* image);
  void EndFrame();

 private:
  int32_t width_;
  int32_t height_;
  int32_t delay_time_;
  std::ofstream ofs_;
  int32_t* last_frame_data_;
};

}  // namespace pyxelcore

#endif  // PYXELCORE_GIF_WRITER_H_
