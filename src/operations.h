// Copyright 2013 Lovell Fuller and others.
// SPDX-License-Identifier: Apache-2.0

#ifndef SRC_OPERATIONS_H_
#define SRC_OPERATIONS_H_

#include <algorithm>
#include <functional>
#include <memory>
#include <tuple>
#include <vips/vips8>

using vips::VImage;

namespace sharp {

  /*
   * Tint an image using the provided RGB.
   */
  VImage Tint(VImage image, std::vector<double> const tint);

  /*
   * Stretch luminance to cover full dynamic range.
   */
  VImage Normalise(VImage image, int const lower, int const upper);

  /*
   * Contrast limiting adapative histogram equalization (CLAHE)
   */
  VImage Clahe(VImage image, int const width, int const height, int const maxSlope);

  /*
   * Gamma encoding/decoding
   */
  VImage Gamma(VImage image, double const exponent);

  /*
   * Flatten image to remove alpha channel
   */
  VImage Flatten(VImage image, std::vector<double> flattenBackground);

  /*
   * Produce the "negative" of the image.
   */
  VImage Negate(VImage image, bool const negateAlpha);

  /*
   * Gaussian blur. Use sigma of -1.0 for fast blur.
   */
  VImage Blur(VImage image, double const sigma, VipsPrecision precision, double const minAmpl);

  /*
   * Convolution with a kernel.
   */
  VImage Convolve(VImage image, int const width, int const height,
    double const scale, double const offset, std::vector<double> const &kernel_v);

  /*
   * Sharpen flat and jagged areas. Use sigma of -1.0 for fast sharpen.
   */
  VImage Sharpen(VImage image, double const sigma, double const m1, double const m2,
    double const x1, double const y2, double const y3);

  /*
    Threshold an image
  */
  VImage Threshold(VImage image, double const threshold, bool const thresholdColor);

  /*
    Perform boolean/bitwise operation on image color channels - results in one channel image
  */
  VImage Bandbool(VImage image, VipsOperationBoolean const boolean);

  /*
    Perform bitwise boolean operation between images
  */
  VImage Boolean(VImage image, VImage imageR, VipsOperationBoolean const boolean);

  /*
    Trim an image
  */
  VImage Trim(VImage image, std::vector<double> background, double threshold, bool const lineArt);

  /*
   * Linear adjustment (a * in + b)
   */
  VImage Linear(VImage image, std::vector<double> const a,  std::vector<double> const b);

  /*
   * Unflatten
   */
  VImage Unflatten(VImage image);

  /*
   * Recomb with a Matrix of the given bands/channel size.
   * Eg. RGB will be a 3x3 matrix.
   */
  VImage Recomb(VImage image, std::vector<double> const &matrix);

  /*
   * Modulate brightness, saturation, hue and lightness
   */
  VImage Modulate(VImage image, double const brightness, double const saturation,
                  int const hue, double const lightness);

  /*
   * Ensure the image is in a given colourspace
   */
  VImage EnsureColourspace(VImage image, VipsInterpretation colourspace);

  /*
   * Split and crop each frame, reassemble, and update pageHeight.
   */
  VImage CropMultiPage(VImage image, int left, int top, int width, int height,
                       int nPages, int *pageHeight);

  /*
   * Split into frames, embed each frame, reassemble, and update pageHeight.
   */
  VImage EmbedMultiPage(VImage image, int left, int top, int width, int height,
                        VipsExtend extendWith, std::vector<double> background, int nPages, int *pageHeight);

  /*
   * Dilate an image
   */
  VImage Dilate(VImage image, int const maskWidth);

  /*
   * Erode an image
   */
  VImage Erode(VImage image, int const maskWidth);
}  // namespace sharp

#endif  // SRC_OPERATIONS_H_
