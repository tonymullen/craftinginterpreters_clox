#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int arc, const char* argv[]) {
  initVM();

  Chunk chunk;
  initChunk(&chunk);

  int constant = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, constant, 123);

  constant = addConstant(&chunk, 3.4);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, constant, 123);

  writeChunk(&chunk, OP_ADD, 123);

  constant = addConstant(&chunk, 5.6);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, constant, 123);

  writeChunk(&chunk, OP_DIVIDE, 123);

  writeChunk(&chunk, OP_NEGATE, 123);
  // writeChunk(&chunk, OP_RETURN, 123);

  // 1 + 2 * 3
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, addConstant(&chunk, 1.0), 123);

  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, addConstant(&chunk, 2.0), 123);

  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, addConstant(&chunk, 3.0), 123);

  writeChunk(&chunk, OP_MULTIPLY, 123);
  writeChunk(&chunk, OP_ADD, 123);

  //writeChunk(&chunk, OP_RETURN, 123);
  // 7

  // 1 + 2 * 3 - 4 / - 5
  // 1
  // 2
  // 3
  // *
  // +
  // 4
  // 5
  // neg
  // /
  // -
  // output: 7.8
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, addConstant(&chunk, 1.0), 123);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, addConstant(&chunk, 2.0), 123);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, addConstant(&chunk, 3.0), 123);
  writeChunk(&chunk, OP_MULTIPLY, 123);
  writeChunk(&chunk, OP_ADD, 123);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, addConstant(&chunk, 4.0), 123);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, addConstant(&chunk, 5.0), 123);
  writeChunk(&chunk, OP_NEGATE, 123);
  writeChunk(&chunk, OP_DIVIDE, 123);
  writeChunk(&chunk, OP_SUBTRACT, 123);
  writeChunk(&chunk, OP_RETURN, 123);


  disassembleChunk(&chunk, "Test chunk");
  interpret(&chunk);
  freeVM();
  freeChunk(&chunk);
  return 0;
}