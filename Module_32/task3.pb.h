// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: task3.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_task3_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_task3_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4024000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4024004 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_task3_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_task3_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_task3_2eproto;
class Company;
struct CompanyDefaultTypeInternal;
extern CompanyDefaultTypeInternal _Company_default_instance_;
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google


// ===================================================================


// -------------------------------------------------------------------

class Company final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Company) */ {
 public:
  inline Company() : Company(nullptr) {}
  ~Company() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR Company(::google::protobuf::internal::ConstantInitialized);

  Company(const Company& from);
  Company(Company&& from) noexcept
    : Company() {
    *this = ::std::move(from);
  }

  inline Company& operator=(const Company& from) {
    CopyFrom(from);
    return *this;
  }
  inline Company& operator=(Company&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Company& default_instance() {
    return *internal_default_instance();
  }
  static inline const Company* internal_default_instance() {
    return reinterpret_cast<const Company*>(
               &_Company_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Company& a, Company& b) {
    a.Swap(&b);
  }
  inline void Swap(Company* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Company* other) {
    if (other == this) return;
    ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Company* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Company>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Company& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const Company& from) {
    Company::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Company* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "Company";
  }
  protected:
  explicit Company(::google::protobuf::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kLegalAddressFieldNumber = 2,
    kNameFieldNumber = 3,
    kActivityTypeFieldNumber = 4,
    kCreationYearFieldNumber = 1,
    kForeignEconomicFieldNumber = 5,
  };
  // required string legalAddress = 2;
  bool has_legaladdress() const;
  void clear_legaladdress() ;
  const std::string& legaladdress() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_legaladdress(Arg_&& arg, Args_... args);
  std::string* mutable_legaladdress();
  PROTOBUF_NODISCARD std::string* release_legaladdress();
  void set_allocated_legaladdress(std::string* ptr);

  private:
  const std::string& _internal_legaladdress() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_legaladdress(
      const std::string& value);
  std::string* _internal_mutable_legaladdress();

  public:
  // required string name = 3;
  bool has_name() const;
  void clear_name() ;
  const std::string& name() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_name(Arg_&& arg, Args_... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* ptr);

  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(
      const std::string& value);
  std::string* _internal_mutable_name();

  public:
  // optional string activityType = 4;
  bool has_activitytype() const;
  void clear_activitytype() ;
  const std::string& activitytype() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_activitytype(Arg_&& arg, Args_... args);
  std::string* mutable_activitytype();
  PROTOBUF_NODISCARD std::string* release_activitytype();
  void set_allocated_activitytype(std::string* ptr);

  private:
  const std::string& _internal_activitytype() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_activitytype(
      const std::string& value);
  std::string* _internal_mutable_activitytype();

  public:
  // required int32 creationYear = 1;
  bool has_creationyear() const;
  void clear_creationyear() ;
  ::int32_t creationyear() const;
  void set_creationyear(::int32_t value);

  private:
  ::int32_t _internal_creationyear() const;
  void _internal_set_creationyear(::int32_t value);

  public:
  // optional bool foreignEconomic = 5;
  bool has_foreigneconomic() const;
  void clear_foreigneconomic() ;
  bool foreigneconomic() const;
  void set_foreigneconomic(bool value);

  private:
  bool _internal_foreigneconomic() const;
  void _internal_set_foreigneconomic(bool value);

  public:
  // @@protoc_insertion_point(class_scope:Company)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<3, 5, 0, 44, 2> _table_;
  template <typename T> friend class ::google::protobuf::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    ::google::protobuf::internal::ArenaStringPtr legaladdress_;
    ::google::protobuf::internal::ArenaStringPtr name_;
    ::google::protobuf::internal::ArenaStringPtr activitytype_;
    ::int32_t creationyear_;
    bool foreigneconomic_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_task3_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Company

// required int32 creationYear = 1;
inline bool Company::has_creationyear() const {
  bool value = (_impl_._has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline void Company::clear_creationyear() {
  _impl_.creationyear_ = 0;
  _impl_._has_bits_[0] &= ~0x00000008u;
}
inline ::int32_t Company::creationyear() const {
  // @@protoc_insertion_point(field_get:Company.creationYear)
  return _internal_creationyear();
}
inline void Company::set_creationyear(::int32_t value) {
  _internal_set_creationyear(value);
  // @@protoc_insertion_point(field_set:Company.creationYear)
}
inline ::int32_t Company::_internal_creationyear() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.creationyear_;
}
inline void Company::_internal_set_creationyear(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000008u;
  _impl_.creationyear_ = value;
}

// required string legalAddress = 2;
inline bool Company::has_legaladdress() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void Company::clear_legaladdress() {
  _impl_.legaladdress_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& Company::legaladdress() const {
  // @@protoc_insertion_point(field_get:Company.legalAddress)
  return _internal_legaladdress();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Company::set_legaladdress(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.legaladdress_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Company.legalAddress)
}
inline std::string* Company::mutable_legaladdress() {
  std::string* _s = _internal_mutable_legaladdress();
  // @@protoc_insertion_point(field_mutable:Company.legalAddress)
  return _s;
}
inline const std::string& Company::_internal_legaladdress() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.legaladdress_.Get();
}
inline void Company::_internal_set_legaladdress(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.legaladdress_.Set(value, GetArenaForAllocation());
}
inline std::string* Company::_internal_mutable_legaladdress() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.legaladdress_.Mutable( GetArenaForAllocation());
}
inline std::string* Company::release_legaladdress() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:Company.legalAddress)
  if ((_impl_._has_bits_[0] & 0x00000001u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* released = _impl_.legaladdress_.Release();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.legaladdress_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return released;
}
inline void Company::set_allocated_legaladdress(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.legaladdress_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.legaladdress_.IsDefault()) {
          _impl_.legaladdress_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Company.legalAddress)
}

// required string name = 3;
inline bool Company::has_name() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline void Company::clear_name() {
  _impl_.name_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline const std::string& Company::name() const {
  // @@protoc_insertion_point(field_get:Company.name)
  return _internal_name();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Company::set_name(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.name_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Company.name)
}
inline std::string* Company::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:Company.name)
  return _s;
}
inline const std::string& Company::_internal_name() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.name_.Get();
}
inline void Company::_internal_set_name(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.name_.Set(value, GetArenaForAllocation());
}
inline std::string* Company::_internal_mutable_name() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000002u;
  return _impl_.name_.Mutable( GetArenaForAllocation());
}
inline std::string* Company::release_name() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:Company.name)
  if ((_impl_._has_bits_[0] & 0x00000002u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000002u;
  auto* released = _impl_.name_.Release();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.name_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return released;
}
inline void Company::set_allocated_name(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  _impl_.name_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.name_.IsDefault()) {
          _impl_.name_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Company.name)
}

// optional string activityType = 4;
inline bool Company::has_activitytype() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline void Company::clear_activitytype() {
  _impl_.activitytype_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000004u;
}
inline const std::string& Company::activitytype() const {
  // @@protoc_insertion_point(field_get:Company.activityType)
  return _internal_activitytype();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Company::set_activitytype(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000004u;
  _impl_.activitytype_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Company.activityType)
}
inline std::string* Company::mutable_activitytype() {
  std::string* _s = _internal_mutable_activitytype();
  // @@protoc_insertion_point(field_mutable:Company.activityType)
  return _s;
}
inline const std::string& Company::_internal_activitytype() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.activitytype_.Get();
}
inline void Company::_internal_set_activitytype(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000004u;
  _impl_.activitytype_.Set(value, GetArenaForAllocation());
}
inline std::string* Company::_internal_mutable_activitytype() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000004u;
  return _impl_.activitytype_.Mutable( GetArenaForAllocation());
}
inline std::string* Company::release_activitytype() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:Company.activityType)
  if ((_impl_._has_bits_[0] & 0x00000004u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000004u;
  auto* released = _impl_.activitytype_.Release();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.activitytype_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return released;
}
inline void Company::set_allocated_activitytype(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000004u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000004u;
  }
  _impl_.activitytype_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.activitytype_.IsDefault()) {
          _impl_.activitytype_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Company.activityType)
}

// optional bool foreignEconomic = 5;
inline bool Company::has_foreigneconomic() const {
  bool value = (_impl_._has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline void Company::clear_foreigneconomic() {
  _impl_.foreigneconomic_ = false;
  _impl_._has_bits_[0] &= ~0x00000010u;
}
inline bool Company::foreigneconomic() const {
  // @@protoc_insertion_point(field_get:Company.foreignEconomic)
  return _internal_foreigneconomic();
}
inline void Company::set_foreigneconomic(bool value) {
  _internal_set_foreigneconomic(value);
  // @@protoc_insertion_point(field_set:Company.foreignEconomic)
}
inline bool Company::_internal_foreigneconomic() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.foreigneconomic_;
}
inline void Company::_internal_set_foreigneconomic(bool value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000010u;
  _impl_.foreigneconomic_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_task3_2eproto_2epb_2eh
