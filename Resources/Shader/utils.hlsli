#ifndef _UTILS_HLSLI_
#define _UTILS_HLSLI_

LightColor CalculateLightColor(int lightIndex, float3 viewNormal, float3 viewPos)
{
	LightColor color = (LightColor) 0.f;
	
	float3 viewLightDir = (float3)0.f;
	
	float diffuseRatio = 0.f;
	float specularRatio = 0.f;
	float distanceRatio = 1.f;

	if (g_light[lightIndex].lightType == 0)
	{
		// Directional Light
		viewLightDir = normalize(mul(float4(g_light[lightIndex].direction.xyz, 0.f), g_matView).xyz);
		diffuseRatio = saturate(dot(-viewLightDir, viewNormal));
	}
	else if (g_light[lightIndex].lightType == 1)
	{
		// Point Light
		float3 viewLightPos = mul(float4(g_light[lightIndex].position.xyz, 1.f), g_matView).xyz;
		viewLightDir = normalize(viewPos - viewLightPos);
		diffuseRatio = saturate(dot(-viewLightDir, viewNormal));

		float dist = distance(viewPos, viewLightPos);
		if (g_light[lightIndex].range == 0.f)
			distanceRatio = 0.f;
		else
			distanceRatio = saturate(1.f-pow(dist / g_light[lightIndex].range, 2));
	}
	else
	{
		// Spot Light
		
	}
	
	float3 reflectionDir = normalize(viewLightDir + 2 * (saturate(dot(-viewLightDir, viewNormal)) * viewNormal));
	float3 eyeDir = normalize(viewPos);
	specularRatio = saturate(dot(-eyeDir, reflectionDir));
	specularRatio = pow(specularRatio, 2);

	color.diffuse = g_light[lightIndex].color.diffuse * diffuseRatio * distanceRatio;
	color.ambient = g_light[lightIndex].color.ambient * distanceRatio;
	color.specular = g_light[lightIndex].color.specular * specularRatio * distanceRatio;
	
	return color;
	}

#endif