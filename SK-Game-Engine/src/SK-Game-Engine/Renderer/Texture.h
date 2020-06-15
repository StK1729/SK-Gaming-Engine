#pragma once
#include <string>
#include "SK-Game-Engine/Core/Core.h"

namespace SK_Game_Engine
{
	class SKGE_API Texture
	{
	public:
		virtual ~Texture() = default;
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual void SetData(void* data, uint32_t size) = 0;
		virtual void Bind(uint32_t slot = 0) const = 0;
	};

	class Texture2D : public Texture
	{
	public:
		virtual ~Texture2D() = default;
		static Ref<Texture2D> Create(const std::string& path);
		static Ref<Texture2D> Create(uint32_t width, uint32_t height);
	};
}