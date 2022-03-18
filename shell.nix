{ pkgs ? import <nixpkgs> {} }:
let
  SDL2_ttf = pkgs.SDL2_ttf.overrideAttrs ( old: 
    rec {
      pname = "SDL2_ttf";
      version = "2.0.18";
      src = pkgs.fetchurl {
          url = "https://www.libsdl.org/projects/SDL_ttf/release/${pname}-${version}.tar.gz";
          sha256 = "sha256-cjTriINRTgGed0fHA+SndFdbGNQ1wipKKdBoy3aKIlE=";
      };
    }
  );
in
pkgs.mkShell {
  name = "slow-browser-env";
  buildInputs = with pkgs; [ 
    cmake gnumake
    gdb
    SDL2 SDL2_ttf
    vulkan-headers
    vulkan-tools
    vulkan-loader
    harfbuzz
  ];
}