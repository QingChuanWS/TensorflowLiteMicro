## `micro`工程现状

- 根据`micro`的依赖情况, 整理出了一个隔离操作系统的`micro`文件夹, 目前`micro`工程已经通过所有官方测试用例,  并可以可以在提供`main`函数时成功编译.
- 目前的版本中并不存在测试文件. 
- 目前工程执行的是根目录下`Application `中的`main.cc` 中的`main`函数, 工程实现了官方自带模型的读入. 编译运行并装载到树莓派板子之后, 可以看到输出`model load successfully!! `的字样.
- `examples` 文件夹中包含了所有官方自带测试用例, 目前只有`micro_speech`语音用例

## 通过的测试用例包括

- `micro` 主目录测试 -- 全部通过测试
  - `memory_helpers_test.cc `

  - `micro_allocator_test.cc` 

  - `micro_error_reporter_test.cc` 

  - `micro_interpreter_test.cc` 

  - `micro_mutable_op_resolver_test.cc` 

  - `micro_string_test.cc`

  - `micro_time_test.cc`

  - `micro_utils_test.cc` 

  - `recording_micro_allocator_test.cc`

  - `simple_memory_allocator_test.cc` 

  - `testing_helpers_test.cc`

- `micro/kernel` 测试 -- 全部通过测试

  - `activations_test.cc` 

  - `add_test.cc` 

  - `arg_min_max_test.cc` 

  - `ceil_test.cc`

  - `circular_buffer_test.cc` 

  - `comparisons_test.cc` 

  - `concatenation_test.cc` 

  - `conv_test.cc` 

  - `depthwise_conv_test.cc`

  - `dequantize_test.cc`

  - `elementwise_test.cc`

  - `floor_test.cc`

  - `fully_connected_test.cc`

  - `l2norm_test.cc`

  - `logical_test.cc`

  - `logistic_test.cc`

  - `maximum_minimum_test.cc`

  - `mul_test.cc`

  - `neg_test.cc`

  - `pack_test.cc`

  - `pad_test.cc`

  - `pooling_test.cc`

  - `prelu_test.cc`

  - `quantization_util_test.cc`

  - `quantize_test.cc`

  - `reduce_test.cc`

  - `reshape_test.cc`

  - `resize_nearest_neighbor_test.cc`

  - `round_test.cc`

  - `softmax_test.cc`

  - `split_test.cc`

  - `strided_slice_test.cc`

  - `sub_test.cc`

  - `svdf_test.cc`

  - `tanh_test.cc`

  - `unpack_test.cc`

- `micro/memory_planner` 测试 -- 全部通过测试

  - `greedy_memory_planner_test.cc`

- `micro/testing` 测试 -- 全部通过测试

  - `util_test.cc`