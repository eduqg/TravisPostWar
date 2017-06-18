cmake_minimum_required (VERSION 3.8.1)
project(postwar LANGUAGES CXX)

set( INCLUDE_DIR "${PROJECT_SOURCE_DIR}" )
set( SRC_DIR "${PROJECT_SOURCE_DIR}/sources" )
set (PROJECT_ASSETS_DIR  "${PROJECT_SOURCE_DIR}")


file(GLOB IMAGES
    "*.png"
)

SET(SOURCES
source/features/Collision/collision.cpp
source/features/Input/input.cpp
source/features/MiscTasks/misktasks.cpp
source/features/Network/network.cpp
source/features/Network/client.cpp
source/features/Network/server.cpp
source/features/RenderWorld/renderworld.cpp
source/features/RenderWorld/draw.cpp
source/features/RenderWorld/video.cpp
source/features/SimulatedWorld/simulated.cpp
source/features/UpdateObjects/updateobjects.cpp
source/features/UpdateTime/update_time.cpp
source/features/MiscTasks/audio.cpp
source/PostWar.cpp
source/features/RenderWorld/load_image.cpp
source/GameFeatures/Menu/menu.cpp
source/GameFeatures/Jogar/jogar.cpp
source/GameFeatures/Creditos/creditos.cpp
source/GameFeatures/Opcoes/opcoes.cpp
source/features/MiscTasks/fontes.cpp
source/GameFeatures/Jogar/Fase1/carregar_fase1.cpp
source/GameFeatures/Jogar/Fase1/carrega_unidades.cpp
source/GameFeatures/Jogar/Fase1/evolucao.cpp
source/GameFeatures/Jogar/Fase1/fase1.cpp
source/features/UpdateObjects/mover_unidade.cpp
source/GameFeatures/Jogar/Fase1/verifica_hexagono.cpp
source/GameFeatures/Jogar/Fase2/carregar_fase2.cpp
source/GameFeatures/Jogar/Fase2/carrega_unidades2.cpp
source/GameFeatures/Jogar/Fase2/fase2.cpp
source/GameFeatures/Jogar/Fase3/carregar_fase3.cpp
source/GameFeatures/Jogar/Fase3/carrega_unidades3.cpp
source/GameFeatures/Jogar/Fase3/fase3.cpp
source/GameFeatures/Jogar/Fase4/carregar_fase4.cpp
source/GameFeatures/Jogar/Fase4/carrega_unidades4.cpp
source/GameFeatures/Jogar/Fase4/fase4.cpp
source/GameFeatures/Jogar/Fase5/carregar_fase5.cpp
source/GameFeatures/Jogar/Fase5/fase5.cpp
source/features/UpdateObjects/ataque_unidade.cpp
source/features/UpdateObjects/dano_ataque.cpp
source/features/UpdateObjects/condicao_fim_do_jogo.cpp
source/GameFeatures/Jogar/venceu_perdeu.cpp
source/GameFeatures/Jogar/coleta_recursos.cpp
source/GameFeatures/blit_tela.cpp)


include_directories("${INCLUDE_DIR}/include ${INCLUDE_DIR}/source/RenderWorld/draw.h ${INCLUDE_DIR}/source/RenderWorld/video.h")

set(COMPILE_FLAGS "${COMPILE_FLAGS} -pedantic -ansi -lm ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")

add_executable(postwar ${SOURCES} ${IMAGES})

target_link_libraries(postwar SDL SDL_image SDL_net SDL_ttf SDL_mixer)

# Copy assets folder to build
add_custom_command(TARGET postwar POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${PROJECT_ASSETS_DIR} ${CMAKE_BINARY_DIR})
