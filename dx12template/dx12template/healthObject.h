#pragma once
#include "headers.h"

class CHealthObject : public CGameObject
{
private:
	SRenderObject m_renderObject;
	SRenderObject m_healthEffectObject;

	float m_healSpeed;
	float m_lastHeal;
	float m_healRadius2;
	float m_maxHealth;
	float m_health;
	float m_veinsSpawnTime;
	float m_lastVeinsSpawnTime;
	float m_hitTime;
	float m_lastHitTime;

private:
	inline void DrawHealthBar() const;

public:
	CHealthObject(SRenderObject const& renderObject);

	virtual void Update() override;
	virtual void FillRenderData() const override;
	virtual Vec2 GetPosition() const override;
	virtual Vec2 GetSize() const override;
	virtual bool NeedDelete() const override;
	virtual void TakeDamage(Vec2 const rotation, float const damage) override;
};