#pragma once

#include <memory>
#include <string>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <map>
#include <filesystem>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <stack>
#include <stddef.h>
#include <utility>
#include <vector>

namespace fs = std::filesystem;

template <typename T>
using Scope = std::unique_ptr<T>;
template <typename T, typename... Args>
constexpr Scope<T> createScope(Args &&...args)
{
	return std::make_unique<T>(std::forward<Args>(args)...);;
}

template <typename T>
using Ref = std::shared_ptr<T>;
template <typename T, typename... Args>
constexpr Ref<T> createRef(Args &&...args)
{
    return std::make_shared<T>(std::forward<Args>(args)...);;
}

//!PTRs 
#define MAKE_SCOPE(className, ...) createScope<className>(__VA_ARGS__)
#define MAKE_REF(className, ...) createRef<className>(__VA_ARGS__)

//!NAMESPACES
#define NAMESPACE(name) namespace name {
#define END_NAMESPACE }

#define ALIAS(origin, replace) \
    using origin = replace;

//!PROPERTIES
#define PROPERTY(type, name) \
    protected: \
        type m_##name; \
    public: \
        const type& get##name() const { return m_##name; } \
        void set##name(const type& value) { m_##name = value; } \

#define PROPERTY_OVERRIDE(type, name) \
    protected: \
        type m_##name; \
    public: \
        const type& get##name() const override { return m_##name; } \
        void set##name(const type& value) { m_##name = value; } \

#define READONLY_PROPERTY(type, name) \
    protected: \
        type m_##name; \
    public: \
        type get##name() const { return m_##name; } \

#define READONLY_PROPERTY_OVERRIDE(type, name) \
    protected: \
        type m_##name; \
    public: \
        type get##name() const override { return m_##name; } \

#define READONLY_PROPERTY_OVERRIDE_GENERIC(type, name) \
    protected: \
        type m_##name; \
    public: \
        template<typename type> \
        type get##name() const override { return m_##name; } \

#define CONST_PROPERTY(type, name, value) \
    protected: \
        const type m_##name = value; \
    public: \
        const type& get##name() const { return m_##name; } \

#define STATIC_PROPERTY(type, name) \
    protected: \
        static type m_##name; \
    public: \
        static const type& get##name() { return m_##name; } \
        static void set_##name(const type& value) { m_##name = value; } \

//!STRUCTURES
#define ENUM(name, ...) \
    enum name { \
        __VA_ARGS__ \
    };

#define ENUM_CLASS(name, ...) \
    enum class name { \
        __VA_ARGS__ \
    };

#define STRUCT(name, ...) \
    struct name { \
        __VA_ARGS__ \
    };

#define GENERIC_STRUCT(name, type, ...) \
    template<typename type> \
    struct name { \
        __VA_ARGS__ \
    };

#define END_ENUM \
    };

#define END_STRUCT \
    };

//!METHODS
#define FUNC(type, name, ...) \
    type name(__VA_ARGS__);

#define FUNC_CONST(type, name, ...) \
    type name(__VA_ARGS__) const;

#define FUNC_VIRTUAL(type, name, ...) \
    virtual type name(__VA_ARGS__) = 0;

#define FUNC_VIRTUAL(type, name, ...) \
    virtual type name(__VA_ARGS__) = 0;

#define FUNC_CONST_VIRTUAL(type, name, ...) \
    virtual type name(__VA_ARGS__) const = 0;

#define FUNC_CONST_VIRTUAL_GENERIC(type, name, ...) \
    template<typename type> \
    virtual type name(__VA_ARGS__) const = 0;

#define FUNC_OVERRIDE(type, name, ...) \
    type name(__VA_ARGS__) override;

#define FUNC_CONST_OVERRIDE(type, name, ...) \
    type name(__VA_ARGS__) const override;

#define FUNC_OVERLOAD(type, name, ...) \
    FUNC(type, name, __VA_ARGS__)

#define FUNC_INLINE(type, name, ...) \
    inline type name() { __VA_ARGS__; }

#define FUNC_INLINE_CONST(type, name, ...) \
    inline type name() const { __VA_ARGS__; }

#define TEMPLATED_FUNC(name, type, returnType, ...) \
    template<typename type> \
    returnType name(__VA_ARGS__){ \

#define FUNC_IMPL(klass, type, name, ...) \
    type klass::name(__VA_ARGS__) { 

#define FUNC_IMPL_CONST(klass, type, name, ...) \
    type klass::name(__VA_ARGS__) const { 

#define FUNC_END }

//!CONSTRUCTORS
#define CTOR(name, ...) \
    name(__VA_ARGS__);

#define TEMPLATED_CTOR(name, type, ...) \
    template<typename type> \
    name(__VA_ARGS__){ 

#define DTOR(name)  \
    ~name();

#define CTOR_IMPL_WITH_PARAMS(klass, ...) \
    klass::klass() : __VA_ARGS__ { \

#define CTOR_IMPL_NO_PARAMS(klass) \
    klass::klass() { \

#define CTOR_END }

#define DTOR_IMPL(klass) \
    klass::~klass() {
#define DTOR_END }

//!CLASSES
#define CLASS(className, ...) \
    class className { \
    public: \
        CTOR(className, __VA_ARGS__); \
        DTOR(className); 

#define TEMPLATED_CLASS(className, type, ...) \
    template<typename type> \
    class className { \
    public: 

#define END_CLASS };

#define INTERFACE(className) \
    class I##className { \
    public: \
        virtual ~I##className() = default;

#define END_INTERFACE };

#define DERIVED_CLASS(className, baseClassName, ...) \
    class className : public baseClassName { \
    public: \
        CTOR(className, __VA_ARGS__) \
        DTOR(className)
        
#define END_DERIVED_CLASS };