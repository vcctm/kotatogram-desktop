/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#include "settings/settings_common.h"

#include "settings/settings_chat.h"
#include "settings/settings_general.h"
#include "settings/settings_information.h"
#include "settings/settings_main.h"
#include "settings/settings_notifications.h"
#include "settings/settings_privacy_security.h"

namespace Settings {

object_ptr<Section> CreateSection(
		Type type,
		not_null<QWidget*> parent,
		UserData *self) {
	switch (type) {
	case Type::Main:
		return object_ptr<::Settings::Main>(parent, self);
	case Type::Information:
		return object_ptr<::Settings::Information>(parent, self);
	case Type::Notifications:
		return object_ptr<::Settings::Notifications>(parent, self);
	case Type::PrivacySecurity:
		return object_ptr<::Settings::PrivacySecurity>(parent, self);
	case Type::General:
		return object_ptr<::Settings::General>(parent, self);
	case Type::Chat:
		return object_ptr<::Settings::Chat>(parent, self);
	}
	Unexpected("Settings section type in Widget::createInnerWidget.");
}

} // namespace Settings