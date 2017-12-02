#ifndef CAFFE_UTIL_TYPE_UTILS_HPP_
#define CAFFE_UTIL_TYPE_UTILS_HPP_

#include "caffe/common.hpp"
#include "caffe/definitions.hpp"
#include "caffe/proto/caffe.pb.h"


namespace caffe {

#define INVALID_DATA_INDEX -1
#define AUX_DATA_INDEX 0
#define HALF_DATA_INDEX 3
#define FLOAT_DATA_INDEX 1
#define DOUBLE_DATA_INDEX 2
#define INT8_QUANTIZED_DATA_INDEX 4
#define INT16_QUANTIZED_DATA_INDEX 5
#define INT32_QUANTIZED_DATA_INDEX 6
#define INT64_QUANTIZED_DATA_INDEX 7

#define PROTO_DATA_INDEX_MIN 1
#define PROTO_DATA_INDEX_MAX 7


template<typename T>
inline size_t safe_sizeof() {
  return sizeof(T);
}

template<>
inline size_t safe_sizeof<void>() {
  return 1;
}

template<>
inline size_t safe_sizeof<const void>() {
  return 1;
}

template<typename T>
inline string safe_type_name() {
  LOG(FATAL) << "Unknown type name" << std::endl;
  return "";
}

template<>
inline string safe_type_name<char>() {
  return "char";
}
template<>
inline string safe_type_name<bool>() {
  return "bool";
}
template<>
inline string safe_type_name<half_fp>() {
  return "half";
}
template<>
inline string safe_type_name<float>() {
  return "float";
}
template<>
inline string safe_type_name<double>() {
  return "double";
}
template<>
inline string safe_type_name<int8_t>() {
  return "int8_t";
}
template<>
inline string safe_type_name<int16_t>() {
  return "int16_t";
}
template<>
inline string safe_type_name<int32_t>() {
  return "int32_t";
}
template<>
inline string safe_type_name<int64_t>() {
  return "int64_t";
}
template<>
inline string safe_type_name<uint8_t>() {
  return "uint8_t";
}
template<>
inline string safe_type_name<uint16_t>() {
  return "uint16_t";
}
template<>
inline string safe_type_name<uint32_t>() {
  return "uint32_t";
}
template<>
inline string safe_type_name<uint64_t>() {
  return "uint64_t";
}
template<>
inline string safe_type_name<void>() {
  return "void";
}

template<typename T>
inline DataType proto_data_type() {
  LOG(FATAL) << "Unknown type" << std::endl;
  return HALF;  // Unreachable
}

template<>
inline DataType proto_data_type<half_fp>() {
  return HALF;
}
template<>
inline DataType proto_data_type<float>() {
  return FLOAT;
}
template<>
inline DataType proto_data_type<double>() {
  return DOUBLE;
}
template<>
inline DataType proto_data_type<int8_t>() {
  return INT8_QUANTIZED;
}
template<>
inline DataType proto_data_type<int16_t>() {
  return INT16_QUANTIZED;
}
template<>
inline DataType proto_data_type<int32_t>() {
  return INT32_QUANTIZED;
}
template<>
inline DataType proto_data_type<int64_t>() {
  return INT64_QUANTIZED;
}


template<typename T>
inline int_tp proto_data_type_index() {
  LOG(FATAL) << "Unknown type" << std::endl;
  return INVALID_DATA_INDEX;  // Unreachable
}

template<>
inline int_tp proto_data_type_index<half_fp>() {
  return HALF_DATA_INDEX;
}
template<>
inline int_tp proto_data_type_index<float>() {
  return FLOAT_DATA_INDEX;
}
template<>
inline int_tp proto_data_type_index<double>() {
  return DOUBLE_DATA_INDEX;
}
template<>
inline int_tp proto_data_type_index<int8_t>() {
  return INT8_QUANTIZED_DATA_INDEX;
}
template<>
inline int_tp proto_data_type_index<int16_t>() {
  return INT16_QUANTIZED_DATA_INDEX;
}
template<>
inline int_tp proto_data_type_index<int32_t>() {
  return INT32_QUANTIZED_DATA_INDEX;
}
template<>
inline int_tp proto_data_type_index<int64_t>() {
  return INT64_QUANTIZED_DATA_INDEX;
}


}  // namespace caffe

#endif  // CAFFE_UTIL_TYPE_UTILS_HPP_
