/******************************************************************************
 *
 * Copyright (C) 2018-2019 Marton Borzak <hello@martonborzak.com>
 *
 * This file is part of the YIO-Remote software project.
 *
 * YIO-Remote software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * YIO-Remote software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with YIO-Remote software. If not, see <https://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *****************************************************************************/
#pragma once

#include <QVariant>

#include "unitsystem.h"

// HELP: anyone knows how to properly define "static const QString" constants across Qt plugin boundaries?
// Workaround: use plain old macros with separated constant definitions in remote_software and the integration plugin.
// Hope there's a better way...
#define CFG_KEY_ID "id"
#define CFG_KEY_FRIENDLYNAME "friendly_name"
#define CFG_KEY_ENTITY_ID "entity_id"
#define CFG_KEY_AREA "area"
#define CFG_KEY_INTEGRATION "integration"
#define CFG_KEY_SUPPORTED_FEATURES "supported_features"
#define CFG_KEY_TYPE "type"
#define CFG_KEY_MDNS "mdns"
#define CFG_KEY_WORKERTHREAD "worker_thread"
#define CFG_OBJ_DATA "data"
#define CFG_KEY_DATA_IP "ip"
#define CFG_KEY_DATA_TOKEN "token"
#define CFG_KEY_DATA_SSL "ssl"
#define CFG_KEY_DATA_SSL_IGNORE "ssl_ignore"

/**
 * @brief This interface is implemented by the Entities object and used by integration DLLs to access the entities.
 */
class ConfigInterface {
 public:
    virtual ~ConfigInterface();

    virtual QVariantMap      getConfig() = 0;
    virtual void             setConfig(const QVariantMap& getConfig) = 0;
    virtual QVariantMap      getSettings() = 0;
    virtual QVariantMap      getAllIntegrations() = 0;
    virtual QVariantMap      getIntegration(const QString& type) = 0;
    virtual QVariantMap      getAllEntities() = 0;
    virtual QVariantList     getEntities(const QString& type) = 0;
    virtual QObject*         getQMLObject(const QString& name) = 0;
    virtual UnitSystem::Enum getUnitSystem() = 0;
};

QT_BEGIN_NAMESPACE
#define ConfigInterface_iid "YIO.ConfigInterface"
Q_DECLARE_INTERFACE(ConfigInterface, ConfigInterface_iid)
QT_END_NAMESPACE
