#include <stdio.h>
#include "objekti.h"

//4,5

OBJECT objs[] = {
   {"an open field"  , "field"   , NULL , NULL  },
   {"a cramped cave"  , "cave"    , NULL , NULL  },
   {"a silver coin"  , "silver"  , field, NULL  },
   {"a gold bar"    , "gold"    , cave , NULL  },
   {"a strong guard"  , "guard"   , field, NULL  },
   {"yourself"       , "yourself", field, NULL  },
   {"a cave entrance", "entrance", field, cave  },
   {"an exit"        , "exit"    , cave , field }
};
