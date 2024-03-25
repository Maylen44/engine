#ifndef ASSETS_MANAGER_H
#define ASSETS_MANAGER_H

/*
What should Assetmanager do?
1) It should store info about assets.
1.1) What info is stable? Path, Types of Assets, List of Names (not the names themself)
1.1) Settings for Assets? Maybe. Default Assets
2) It should make background operations on Assets: load, adjust, deload etc.
3) It should give oportunity of adjusting the Assets from outside?
3.1) Which adjustment? Will need to find out
4) It should do actions with assets based on outside comands, like play SFX at the right time
*/


struct AssetsPOD
{

};

class AssetsManager
{
public:
	AssetsManager();
	~AssetsManager();

private:

};

#endif //ASSETS_MANAGER_H