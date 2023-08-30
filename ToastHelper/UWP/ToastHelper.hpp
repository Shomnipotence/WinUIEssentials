#include <winrt/Windows.UI.Notifications.h>
#include <winrt/Windows.Data.Xml.Dom.h>
#include <format>

template<typename Derived>
class IToastBase
{
protected:
    static auto loadXml(auto&&... args)
    {
        winrt::Windows::Data::Xml::Dom::XmlDocument doc;
        doc.LoadXml(std::format(Derived::m_schema, args...));
        return doc;
    }
};

class BodyTextOnly : IToastBase<BodyTextOnly>
{
public:
    static auto Get(std::wstring_view bodyText)
    {
        return loadXml(bodyText);
    }
private:
    constexpr auto static m_schema = LR"(<toast>
    <visual>
        <binding template="ToastText01">
            <text id="1">{}</text>
        </binding>  
    </visual>
</toast>)";
    friend class IToastBase<BodyTextOnly>;
};

class SingleLineHeaderWithBodyText : IToastBase<SingleLineHeaderWithBodyText>
{
public:
    static auto Get(std::wstring_view header, std::wstring_view body)
    {
        return loadXml(header, body);
    }
private:
    constexpr auto static m_schema = LR"(<toast>
    <visual>
        <binding template="ToastText02">
            <text id="1">{}</text>
            <text id="2">{}</text>
        </binding>  
    </visual>
</toast>)";
    friend class IToastBase<SingleLineHeaderWithBodyText>;
};

class TwoLineHeaderWithBodyText : IToastBase<TwoLineHeaderWithBodyText>
{
public:
    static auto Get(std::wstring_view header, std::wstring_view body)
    {
        return loadXml(header, body);
    }
private:
    constexpr auto static m_schema = LR"(<toast>
    <visual>
        <binding template="ToastText03">
            <text id="1">{}</text>
            <text id="2">{}</text>
        </binding>  
    </visual>
</toast>)";
    friend class IToastBase<TwoLineHeaderWithBodyText>;
};

class HeaderWithTwoSingleLineBody : IToastBase<HeaderWithTwoSingleLineBody>
{
public:
    static auto Get(std::wstring_view header, std::wstring_view body1, std::wstring_view body2)
    {
        return loadXml(header, body1, body2);
    }
private:
    constexpr auto static m_schema = LR"(<toast>
    <visual>
        <binding template="ToastText04">
            <text id="1">{}</text>
            <text id="2">{}</text>
            <text id="3">{}</text>
        </binding>  
    </visual>
</toast>)";
    friend class IToastBase<HeaderWithTwoSingleLineBody>;
};

class ImageWithBodyOnly : IToastBase<ImageWithBodyOnly>
{
public:
    static auto Get(std::wstring_view image, std::wstring_view header)
    {
        return loadXml(image, header);
    }
private:
    constexpr auto static m_schema = LR"(<toast>
    <visual>
        <binding template="ToastImageAndText01">
            <image id="1" src="{0}" alt="{0}"/>
            <text id="1">{1}</text>
        </binding>  
    </visual>
</toast>)";
    friend class IToastBase<ImageWithBodyOnly>;
};

class ImageWithHeaderAndBody : IToastBase<ImageWithHeaderAndBody>
{
public:
    static auto Get(std::wstring_view image, std::wstring_view header, std::wstring_view body)
    {
        return loadXml(image, header, body);
    }
private:
    constexpr auto static m_schema = LR"(<toast>
    <visual>
        <binding template="ToastImageAndText02">
            <image id="1" src="{0}" alt="{0}"/>
            <text id="1">{1}</text>
            <text id="2">{2}</text>
        </binding>  
    </visual>
</toast>)";
    friend class IToastBase<ImageWithHeaderAndBody>;
};

class ImageWithTwoLineHeaderAndBody : IToastBase<ImageWithTwoLineHeaderAndBody>
{
public:
    static auto Get(std::wstring_view image, std::wstring_view header, std::wstring_view body)
    {
        return loadXml(image, header, body);
    }
private:
    constexpr auto static m_schema = LR"(<toast>
    <visual>
        <binding template="ToastImageAndText03">
            <image id="1" src="{0}" alt="{0}"/>
            <text id="1">{1}</text>
            <text id="2">{2}</text>
        </binding>  
    </visual>
</toast>)";
    friend class IToastBase<ImageWithTwoLineHeaderAndBody>;
};

class ImageWithHeaderAndTwoSingleLineBody : IToastBase<ImageWithHeaderAndTwoSingleLineBody>
{
public:
    static auto Get(std::wstring_view image, std::wstring_view header, std::wstring_view body1, std::wstring_view body2)
    {
        return loadXml(image, header, body1, body2);
    }
private:
    constexpr auto static m_schema = LR"(<toast>
    <visual>
        <binding template="ToastImageAndText04">
            <image id="1" src="{0}" alt="{0}"/>
            <text id="1">{1}</text>
            <text id="2">{2}</text>
            <text id="3">{3}</text>
        </binding>  
    </visual>
</toast>)";
    friend class IToastBase<ImageWithHeaderAndTwoSingleLineBody>;
};