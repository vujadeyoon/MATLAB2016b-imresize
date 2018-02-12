# MATLAB2016b-imresize
C implementation of MATLAB built-in function, imresize()

## Table of contents
1. [Development environments](#dev_env)
2. [Usages](#usage)
3. [Note](#note)

## Development environments <a name="dev_env"></a>
* Coding language: C language
* Integrated Development Environment(IDE): Microsoft Visual Studio 2017

## Usages <a name="usage"></a>
```c
out_zoom = imresize(&ori, &out_img_sz_zoom, nearest, true);   // Nearest neighborhood, Zoom, Anti-aliasing option: true (should not be working because of zooming)
out_down = imresize(&ori, &out_img_sz_down, nearest, true);   // Nearest neighborhood, Down-scaling, Anti-aliasing option: true (should not be working because of 'nearest' option)
out_zoom = imresize(&ori, &out_img_sz_zoom, bilinear, false); // Bilinear, Zoom, Anti-aliasing option: false
out_down = imresize(&ori, &out_img_sz_down, bilinear, false); // Bilinear, Down-scaling, Anti-aliasing option: false
out_zoom = imresize(&ori, &out_img_sz_zoom, bicubic, true);   // Bicubic, Zoom, Anti-aliasing option: true (should not be working because of zooming)
out_down = imresize(&ori, &out_img_sz_down, bicubic, true);   // Bicubic, Down-scaling, Anti-aliasing option: true
out_zoom = imresize(&ori, &out_img_sz_zoom, lanczos2, false); // Lanczos2, Zoom, Anti-aliasing option: false
out_down = imresize(&ori, &out_img_sz_down, lanczos2, true);  // Lanczos2, Down-scaling, Anti-aliasing option: true
out_zoom = imresize(&ori, &out_img_sz_zoom, lanczos3, false); // Lanczos3, Zoom, Anti-aliasing option: false
out_down = imresize(&ori, &out_img_sz_down, lanczos3, true);  // Lanczos3, Down-scaling, Anti-aliasing option: ture
```

## Note <a name="note"></a>
* Please note that anti-aliasing filters should be applied when down-scaling images.
* However, the nearest neighborhood interpolation method does not require applying anti-aliasing filters as a default.
