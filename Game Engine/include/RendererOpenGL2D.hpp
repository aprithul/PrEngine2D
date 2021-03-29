//
//  Display.h
//  Game Engine
//
//  Created by Aniruddha Prithul on 7/22/17.
//  Copyright © 2017 Aniruddha Prithul. All rights reserved.
//

#ifndef RENDERER_OPENGL_2D_HPP
#define RENDERER_OPENGL_2D_HPP

#include "tiny_obj_loader.h"
#include "GlAssert.hpp"

#include "Material.hpp"
#include "Graphics.hpp"
#include "Module.hpp"
#include "RenderLayer.hpp"
#include "GeometryLayer.hpp"
#include "SpriteLayer.hpp"
#include "ShapesLayer.hpp"
#include "GuiLayer.hpp"
#include <vector>

namespace PrEngine {

    struct RendererOpenGL2D : public Module
    {
			std::vector<RenderLayer*> render_layers;
			std::vector<Graphic> static_batches;

			// display attributes
			Int_32 height;
			Int_32 width;

			// viewport attributes
			Vector2<Float_32> viewport_pos;
			Vector2<Float_32> viewport_size;

			std::string title;

			// constructor/ destructors
			RendererOpenGL2D(Int_32 width, Int_32 height, Bool_8 full_screen, std::string& title, std::string module_name,Int_32 priority);
			~RendererOpenGL2D();
			void update_viewport_size(int x, int y, int width, int height);
			void init();
			// clears the display with the color specified
			void Clear(Float_32 r, Float_32 g, Float_32 b, Float_32 a);
			// swaps buffers in a Double_64 buffer environment
			void SwapBuffers();
			void set_vsync(GLboolean value);
			Bool_8 make_shader_program(const std::string& path, GLuint& shader_program);
			GLuint make_shader( GLenum type, const std::string& source);
			//void generate_batched_sprite_graphics(Uint_32 graphic_id);
			void generate_sprite_graphics(Uint_32 graphic_id);
			void draw_line(Vector3<Float_32> p1, Vector3<Float_32> p2, Vector4<Float_32> color);
			void draw_rect(Rect<Float_32> rect, Vector4<Float_32> color);
			void draw_rect_with_transform(Rect<Float_32> rect, Vector4<Float_32> color, Matrix4x4<Float_32> transformation);
			RenderLayer* get_layer(const std::string& layer_name);
			void prepare_batches(std::vector<Uint_32> batched_grphic_ids, Uint_32 usage);
			//void prepare_dynmic_batches(std::vector<Uint_32> batched_grphic_ids);
			//Matrix4x4<Float_32> view_matrix;
			//Matrix4x4<Float_32> projection;

			void start() override;
			void update() override;
			void end() override;
			// reference to the sdl window
			SDL_Window* window;
			// the opengl context used with the window
			SDL_GLContext glContext;

			//static std::unordered_map<Uint_32, Uint_32> texture_to_index;
    };

	extern RendererOpenGL2D* renderer;


}

#endif /* Display_h */
