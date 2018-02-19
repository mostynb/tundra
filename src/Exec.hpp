#ifndef EXEC_HPP
#define EXEC_HPP

#include "stddef.h"

namespace t2
{
  struct NodeData;
  struct MemAllocHeap;
  struct BuildQueue;

  struct EnvVariable
  {
    const char *m_Name;
    const char *m_Value;
  };

  struct OutputBufferData
  {
     char* buffer;
     size_t buffer_size;
     int cursor;
     MemAllocHeap* heap;
  };

  struct ExecResult
  {
    int               m_ReturnCode;
    bool              m_WasSignalled;
    NodeData*         m_FrozenNodeData;
    OutputBufferData  m_StdOutBuffer;
    OutputBufferData  m_StdErrBuffer;
  };

  void InitOutputBuffer(OutputBufferData* data, MemAllocHeap* heap);
  void ExecResultFreeMemory(ExecResult* result);
  void ExecInit();

  ExecResult ExecuteProcess(
        const char*         cmd_line,
        int                 env_count,
        const EnvVariable*  env_vars,
        MemAllocHeap*       heap,
        int                 job_id,
        bool                stream_output_to_stdout=false
        ); 
}

#endif
