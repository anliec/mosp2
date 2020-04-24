/**
 * \file ObjectFactory.h
 */

#ifndef ObjectFactory_h
#define ObjectFactory_h

#include <map>
#include <memory>

#include "ObjectDescriptor.h"
#include "BagObject.h"
#include "BagItem.h"
#include "BagWeapon.h"


class ObjectFactory {
  private:
    std::map<int,ObjectDescriptor> objectInfo;

    static std::shared_ptr<ObjectFactory> factory;
  protected:
  public:

  private:
    ObjectFactory()
    {
      // @todo
    }

  public:
    /**
     */
    static void createFactory() {
      // @todo 
    }

    /**
     *  @return shared_ptr<ObjectFactory>
     */
    static std::shared_ptr<ObjectFactory> getFactory() {
        return factory;
    }

    /**
     *  @param objectId TBD
     *  @param count TBD
     *  @return shared_ptr<BagObject>
     */
    std::shared_ptr<BagObject> createObject(const int& objectId, const int& count=1) {
        auto info = objectInfo.find(objectId);
        if(info != objectInfo.end()){
            if(info->second.weaponAttack != nullptr){

                if(info->second.itemCharac != nullptr){

                }
            }
            else if(info->second.itemCharac != nullptr){

            }
            else {
                return std::make_shared<BagObject>(objectId, info->second.objectWeight, count);
            }
        }
        else{
            return std::make_shared<BagObject>(objectId, 1, count);
        }
    }


  // Protected methods
  protected:

  // Private methods
  private:
};

#endif // ObjectFactory_h
