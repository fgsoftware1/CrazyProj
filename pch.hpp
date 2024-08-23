#pragma once

#define GLFW_INCLUDE_NONE

#include <memory>
#include <string>
#include <iostream>

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

#define NAMESPACE(name) namespace name {
#define END_NAMESPACE }

#define PROPERTY(type, name) \
    protected: \
        type m_##name; \
    public: \
        const type& get_##name() const { return m_##name; } \
        void set_##name(const type& value) { m_##name = value; }

#define READONLY_PROPERTY(type, name) \
    protected: \
        type m_##name; \
    public: \
        const type get_##name() const { return m_##name; }

#define CONST_PROPERTY(type, name, value) \
    protected: \
        const type m_##name = value; \
    public: \
        const type& get_##name() const { return m_##name; }

#define STATIC_PROPERTY(type, name) \
    protected: \
        static type m_##name; \
    public: \
        static const type& get_##name() { return m_##name; } \
        static void set_##name(const type& value) { m_##name = value; }

#define CTOR(name, ...) \
    name(__VA_ARGS__);

#define DTOR(name)  \
    ~name() = default;

#define FUNC(type, name, ...) \
    type name(__VA_ARGS__);

#define FUNC_OVERRIDE(type, name, ...) \
    type name(__VA_ARGS__) override;

#define FUNC_OVERLOAD(type, name, ...) \
    FUNC(type, name, __VA_ARGS__)

#define CTOR_IMPL(klass, ...) \
    klass::klass(__VA_ARGS__) {
#define CTOR_END }

#define DTOR_IMPL(klass) \
    ~klass::klass() {
#define DTOR_END }

#define FUNC_IMPL(klass, type, name, ...) \
    type klass::name(__VA_ARGS__) { \

#define FUNC_END }

#define CLASS(className, ...) \
    class className { \
    public: \
        CTOR(className, __VA_ARGS__); \
        DTOR(className); 

#define END_CLASS };

#define INTERFACE(className) \
    class I##className { \
    public: \
        virtual ~I##className() = default;

#define END_INTERFACE };

#define DERIVED_CLASS(className, baseClassName, ...) \
    class className : public baseClassName { \
    public: \
        className(__VA_ARGS__); \
        
#define END_DERIVED_CLASS };