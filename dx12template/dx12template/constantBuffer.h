#pragma once

__declspec(align(256))
struct CBObject
{
	Matrix4x4 m_objectToScreen;
	Vec4 m_colorScale;
	Vec2 m_uvTile;
	Vec2 m_uvOffset;
	Vec2 m_offset;
};
