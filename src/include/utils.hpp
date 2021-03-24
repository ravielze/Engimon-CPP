#include "lib/constant/ItemType.hpp"
#include "lib/constant/Element.hpp"
#include "lib/constant/EntitySource.hpp"
#include "lib/constant/MapEntity.hpp"
string convertItemTypeToString(ItemType it);
string convertElementToString(Element e);
string convertEntitySourceToString(EntitySource es);
string mapLegend(Entity e, MapTerrain t);
EntityType mapEntityType(Entity e);