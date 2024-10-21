# Darktide-Reversed

## Project

I already started the Unit export project in `UnitExtract` written in c++ just so I can write less and reuse more of the decompiled version. But it's up to debate what's the best approach at this point.

## Source code

Headers and decompiled functions. More than we need, actually.

Ask for pw from the repo owner.

## Hints

* `stingray::UnitResource::serialize<stingray::InputArchive>()` - serializes units
* `stingray::Application::setup_resources()` - deserialize ALL resource types

## Instructions (optional)

If you want to come to your own conclusions in IDA, follow these steps:

1. Download the latest (2018) Stingray SDK [here](https://www.mutaz.pro/free-programs/en/download/?630)
2. Be brave and install this package from an unknown source
3. Locate `\Autodesk\Stingray\1.9.1494.0\engine\win64\dev\stingray_win64_dev.exe`
4. Run IDA on it, then `File / Load File / Load PDB` and locate `stingray_win64_dev.pdb`
5. Start browsing the well annotated source