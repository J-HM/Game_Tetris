#include "block.h"

using std::vector;

const vector<vector<vector<bool>>> IBlock::k_block_shape_list_ =
{
  {  { 0, 0, 0, 0 },
     { 1, 1, 1, 1 },
     { 0, 0, 0, 0 },
     { 0, 0, 0, 0 }  },

  {  { 0, 0, 1, 0 },
     { 0, 0, 1, 0 },
     { 0, 0, 1, 0 },
     { 0, 0, 1, 0 }  },

  {  { 0, 0, 0, 0 },
     { 0, 0, 0, 0 },
     { 1, 1, 1, 1 },
     { 0, 0, 0, 0 }  },

  {  { 0, 1, 0, 0 },
     { 0, 1, 0, 0 },
     { 0, 1, 0, 0 },
     { 0, 1, 0, 0 }  },
};

const vector<vector<vector<bool>>> OBlock::k_block_shape_list_ =
{
  {  { 0, 1, 1, 0 },
     { 0, 1, 1, 0 },
     { 0, 0, 0, 0 },  }
};
